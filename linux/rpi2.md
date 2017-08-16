

U-Boot 
======

Loader
------
	
	# in config.txt
	kernel=u-boot.bin

	sudo chmod a+rw /dev/ttyUSB0
	minicom -D /dev/ttyUSB0

Build
-----

	git clone git://git.denx.de/u-boot.git

	make O=build_pi2 rpi_2_defconfig 
	make menuconfig O=build_pi2
	make O=build_pi2

	#!!! command + f


Source
------

	DTS: arch/arm/dts/bcm2836-rpi-2-b.dts
	config: rpi.h
	link addr: 00008000


Env
------


	arch=arm
	baudrate=115200
	board=rpi_2
	board_name=2 Model B
	board_rev=0x4
	board_rev_scheme=1
	board_revision=0xA01041
	boot_a_script=load ${devtype} ${devnum}:${distro_bootpart} ${scriptaddr} ${prefix}${script}; source ${sc}
	boot_efi_binary=load ${devtype} ${devnum}:${distro_bootpart} ${kernel_addr_r} efi/boot/bootarm.efi; boot}
	boot_extlinux=sysboot ${devtype} ${devnum}:${distro_bootpart} any ${scriptaddr} ${prefix}extlinux/extlinf
	boot_net_usb_start=usb start
	boot_prefixes=/ /boot/
	boot_script_dhcp=boot.scr.uimg
	boot_scripts=boot.scr.uimg boot.scr
	boot_targets=mmc0 usb0 pxe dhcp 
	bootargs=earlyprintk console=ttyAMA0,115200 root=/dev/mmcblk0p2 rootfstype=ext4 r
	bootcmd=run distro_bootcmd
	bootcmd_dhcp=run boot_net_usb_start; if dhcp ${scriptaddr} ${boot_script_dhcp}; then source ${scriptaddri
	bootcmd_mmc0=setenv devnum 0; run mmc_boot
	bootcmd_pxe=run boot_net_usb_start; dhcp; if pxe get; then pxe boot; fi
	bootcmd_usb0=setenv devnum 0; run usb_boot
	bootdelay=2
	cpu=armv7
	distro_bootcmd=for target in ${boot_targets}; do run bootcmd_${target}; done
	efi_dtb_prefixes=/ /dtb/ /dtb/current/
	ethaddr=b8:27:eb:a1:8b:32
	fdt_addr_r=0x00000100
	fdt_high=ffffffff
	fdtfile=bcm2836-rpi-2-b.dtb
	fileaddr=100
	filesize=3bfc
	initrd_high=ffffffff
	kernel_addr_r=0x01000000
	load_efi_dtb=load ${devtype} ${devnum}:${distro_bootpart} ${fdt_addr_r} ${prefix}${fdtfile}; fdt addr ${}
	loadaddr=0x00200000
	mmc_boot=if mmc dev ${devnum}; then setenv devtype mmc; run scan_dev_for_boot_part; fi
	preboot=usb start
	pxefile_addr_r=0x00100000
	ramdisk_addr_r=0x02100000
	scan_dev_for_boot=echo Scanning ${devtype} ${devnum}:${distro_bootpart}...; for prefix in ${boot_prefixe;
	scan_dev_for_boot_part=part list ${devtype} ${devnum} -bootable devplist; env exists devplist || setenv e
	scan_dev_for_efi=for prefix in ${efi_dtb_prefixes}; do if test -e ${devtype} ${devnum}:${distro_bootpart 
	scan_dev_for_extlinux=if test -e ${devtype} ${devnum}:${distro_bootpart} ${prefix}extlinux/extlinux.confi
	scan_dev_for_scripts=for script in ${boot_scripts}; do if test -e ${devtype} ${devnum}:${distro_bootparte
	scriptaddr=0x02000000
	serial#=0000000016a18b32
	soc=bcm283x
	stderr=serial,lcd
	stdin=serial,usbkbd
	stdout=serial,lcd
	usb_boot=usb start; if usb dev ${devnum}; then setenv devtype usb; run scan_dev_for_boot_part; fi
	usbethaddr=b8:27:eb:a1:8b:32
	vendor=raspberrypi


	fatload mmc 0:1 0x01000000 zImage
	fatload mmc 0:1 0x00000100 bcm2709-rpi-2-b.dtb
	bootz 0x01000000 - 0x00000100

	dhcp uImage.new
	fatload mmc 0:1 0x00000100 bcm2709-rpi-2-b.dtb
	setenv bootargs earlyprintk console=ttyAMA0,115200
	bootm 0x200000 - 0x00000100

	
Kernel
======

arm support zImage, uImage is a wrapper of zImage.

	scripts/mkuboot.sh
	scripts/Makefile.lib:MKIMAGE := $(srctree)/scripts/mkuboot.sh


1. kernel link to 80008000 from System.map, but in uboot 80008000 not accessible. 
decompress code must did some memory op.


	mkimage -A arm -O linux -C none  -T kernel -a 0x00008000 -e 0x00008000 -n 'Linux-4.4.7-rt9+' -d arch/arm/boot/zImage uImage

	/bin/bash ./scripts/mkuboot.sh -A arm -O linux -C none  -T kernel -a 0x00008000 -e 0x00008000 -n 'Linux-4.4.7-rt9+' -d arch/arm/boot/zImage arch/arm/boot/uImage
	Image Name:   Linux-4.4.7-rt9+
	Created:      Wed Aug 16 23:01:30 2017
	Image Type:   ARM Linux Kernel Image (uncompressed)
	Data Size:    6824408 Bytes = 6664.46 kB = 6.51 MB
	Load Address: 00008000
	Entry Point:  00008000

