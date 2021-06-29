#!/usr/bin/env bash
if [ $(uname -a ) -ne "FreeBSD" ]; then
	echo "This script must be run on a FreeBSD system!"
	exit
fi
if [ "$EUID" -ne 0 ]; then
	echo "This script must be run as root."
	exit
fi
cp -rv bin $HOME/bin
cp -rv .config $HOME/.config 
cp -rv sysconfig/etc/rc.conf /etc/rc.conf
cp -rv sysconfig/loader.conf /boot/loader.conf
pkg install $(cat prime-list)
echo "Now reboot."
