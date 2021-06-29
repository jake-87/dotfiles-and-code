#! /usr/local/bin/bash
echo "This will remove any drm, then reinstall from ports."
pkg remove drm-kmod drm-fbsd12.0-kmod
cd /usr/ports/graphics/drm-kmod
make clean
make install -j4
cd ../drm-fbsd12.0-kmod
make clean
make install
echo "Finished. Uncomment loader.conf and rc.conf and reboot."
