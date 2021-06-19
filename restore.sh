#!/usr/bin/env bash
if [ $(uname -a ) -ne "FreeBSD" ]; then
	echo "This script must be run on a FreeBSD system!"
	exit
fi
if [ "$EUID" -ne 0 ]; then
	echo "This script must be run as root."
	exit
fi
cp .config $HOME/.config 
cp sysconfig/etc/rc.conf /etc/rc.conf
cp sysconfig/loader.conf /boot/loader.conf
pkg install $(cat prime-list)
echo "Now reboot."
