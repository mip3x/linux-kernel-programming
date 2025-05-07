# hello-2
Build guide

## Make
```bash
make
```

## Insert module
```bash
sudo insmod hello-2.ko
```

## Get info about module
```bash
sudo lsmod | grep hello-2.ko
```

## Remove module
```bash
sudo rmmod hello-2.ko
```

## See output
```bash
sudo dmesg
```
