# hello-1
Build guide

## Make
```bash
make
```

## Insert module
```bash
sudo insmod hello-1.ko
```

## Get info about module
```bash
sudo lsmod | grep hello-1.ko
```

## Remove module
```bash
sudo rmmod hello-1.ko
```

## See output
```bash
sudo dmesg
```
