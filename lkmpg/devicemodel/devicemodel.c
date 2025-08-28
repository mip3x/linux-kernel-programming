#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/version.h>

#define DEVICE_MODEL_NAME "devicemodel_example"

struct devicemodel_data {
    char *greeting;
    int number;
};

static int devicemodel_probe(struct platform_device *dev) {
    struct devicemodel_data *pd =
        (struct devicemodel_data *)(dev->dev.platform_data);
    
    pr_info("devicemodel probe\n");
    pr_info("devicemodel greeting: %s; %d\n", pd->greeting, pd->number);

    /* device initialization code */

    return 0;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 11, 0)
static void devicemodel_remove(struct platform_device *dev) {
    pr_info("devicemodel example removed\n");
    /* device removal code */
}
#else
static int devicemodel_remove(struct platform_device *dev) {
    pr_info("devicemodel example removed\n");
    /* device removal code */
    return 0;
}
#endif

static int devicemodel_suspend(struct device *dev) {
    pr_info("devicemodel example suspend\n");
    /* device suspend code */
    return 0;
}

static int devicemodel_resume(struct device *dev) {
    pr_info("devicemodel example resume\n");
    /* device resume code */
    return 0;
}

static const struct dev_pm_ops devicemodel_pm_ops = {
    .suspend = devicemodel_suspend,
    .resume = devicemodel_resume,
    .poweroff = devicemodel_suspend,
    .freeze = devicemodel_suspend,
    .thaw = devicemodel_resume,
    .restore = devicemodel_resume,
};

static struct platform_driver devicemodel_driver = {
    .driver = {
        .name = DEVICE_MODEL_NAME,
        .pm = &devicemodel_pm_ops,
    },
    .probe = devicemodel_probe,
    .remove = devicemodel_remove,
};

static int __init devicemodel_init(void) {
    int ret;

    pr_info("devicemodel init\n");

    ret = platform_driver_register(&devicemodel_driver);

    if (ret) {
        pr_err("Unable to register driver\n");
        return ret;
    }

    return 0;
}

static void __exit devicemodel_exit(void) {
    pr_info("devicemodel exit\n");
    platform_driver_unregister(&devicemodel_driver);
}

module_init(devicemodel_init);
module_exit(devicemodel_exit);

MODULE_LICENSE("GPL");