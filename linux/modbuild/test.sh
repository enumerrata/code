#!/bin/bash

make
sudo insmod my_mod.ko
lsmod | grep my_mod
sudo rmmod my_mod.ko
sudo dmesg -c
