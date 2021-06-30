#!/usr/bin/env bash
mkdir $HOME/Documents
cp -rv small-projects $HOME/Documents/
cp -rv zshrc $HOME/.zshrc
cp -rv bin $HOME/bin
cp -rv .config $HOME/.config
doas rm -rv /etc/rc.conf
doas cp -rv sysconfig/etc/rc.conf /etc/rc.conf
doas rm -rf /boot/loader.conf
doas cp -rv sysconfig/loader.conf /boot/loader.conf
doas pkg install $(cat prime-list)
echo "Now reboot."
