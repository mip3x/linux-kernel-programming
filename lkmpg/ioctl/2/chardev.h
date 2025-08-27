/*
* chardev.h - the header file with the ioctl definitions.
*
* The declarations here have to be in a header file, because they need
* to be known both to the kernel module (in chardev2.c) and the process
* calling ioctl() (in userspace_ioctl.c).
*/

#ifndef CHARDEV_H
#define CHARDEV_H

#include <linux/ioctl.h>

/* The major device number. We can not rely on dynamic registration
*  any more, because ioctls need to know it.
*/
#define MAJOR_NUM 100

#define IOCTL_SET_MSG _IOW(MAJOR_NUM, 0, char*)
/* _IOW means that we are creating an ioctl command number for passing
* information from a user process to the kernel module.
*
* The first arguments, MAJOR_NUM, is the major device number we are using.
*
* The second argument is the number of the command (there could be several
* with different meanings).
*
* The third argument is the type we want to get from the process to the
*/

#define IOCTL_GET_MSG _IOR(MAJOR_NUM, 1, char*)
#define IOCTL_GET_NTH_BYTE _IOWR(MAJOR_NUM, 2, int)

#define DEVICE_FILE_NAME "char_dev"
#define DEVICE_PATH "/dev/char_dev"

#endif