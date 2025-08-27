#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdint.h>

struct ioctl_arg {
    unsigned int val;
};

#define IOC_MAGIC '\x66'
#define IOCTL_VALSET _IOW(IOC_MAGIC, 0, struct ioctl_arg)
#define IOCTL_VALGET _IOR(IOC_MAGIC, 1, struct ioctl_arg)
#define IOCTL_VALGET_NUM _IOR(IOC_MAGIC, 2, int)
#define IOCTL_VALSET_NUM _IOW(IOC_MAGIC, 3, int)

int main(void) {
    int fd = open("/dev/ioctltest", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // set val = 0x7A
    struct ioctl_arg a = {
        .val = 0x7A
    };
    if (ioctl(fd, IOCTL_VALSET, &a) == -1)
        perror("IOCTL_VALSET");

    // get val
    memset(&a, 0, sizeof(a));
    if (ioctl(fd, IOCTL_VALGET, &a) == -1) 
        perror("IOCTL_VALGET");
    printf("VALGET: 0x%02X\n", a.val & 0xFF);

    // set/get ioctl_num
    int num = 1234;
    if (ioctl(fd, IOCTL_VALSET_NUM, &num) == -1) 
        perror("VALSET_NUM");

    int out = -1;
    if (ioctl(fd, IOCTL_VALGET_NUM, &out) == -1)
        perror("VALGET_NUM");
    printf("VALGET_NUM: %d\n", out);

    close(fd);
    return 0;
}

