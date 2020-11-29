ASM_SOURCES += arch/x86/boot/boot.s

boot: dist/featheros.bin
	qemu-system-i386 -m 512 -kernel $<

debug: dist/featheros.bin
	qemu-system-i386 -s -S -m 512 -kernel $<
