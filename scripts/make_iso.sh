#!/bin/bash

if [[ $# -ne  2 ]]; then
  echo "usage: make_iso.sh <kernel> <destdir>";
  exit 1;
fi
KERNEL=$1
DESTDIR=$2

TMPDIR=$(mktemp -d)

trap "rm -rf $TMPDIR" exit

mkdir -p $TMPDIR/boot/grub
cp $KERNEL $TMPDIR/boot


cat << EOF >> $TMPDIR/boot/grub.cfg
menuentry "FeatherOS" {
  multiboot /boot/$(basename $KERNEL)
}
EOF

grub-mkrescue -o ${DESTDIR}/featheros.iso $TMPDIR
