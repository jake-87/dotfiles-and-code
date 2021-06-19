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
pkg install "ImageMagick7 alsa-utils bash bashtop -py38 browsh cmake cmatrix curl dialog4ports doas dosbox drm-current-kmod drm-kmod feh firefox fortune-mod-freebsd-classic fusefs-exfat gawk gcc gdb git gmake gnulib grim hack-font hello hexyl libjpeg-turbo libreoffice linux-c7 linux-c7-ltp lolcat lynx markdown musescore neovim noto onefetch pfetch pkg pkg-provides poppler-utils poudriere py27-pip py38-glances py38-pip python2 python3 rofi rust slurp sway terminator valgrind vim-console virtualbox-ose virtualbox-ose-kmod wayland wget xev xpdf zsh "
echo "Now reboot."
