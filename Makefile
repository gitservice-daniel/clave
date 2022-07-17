build-x86:
	@ cd kernel && make build-x86-kernel
	@ mkdir -p iso_root/boot/grub
	@ mkdir -p dist/x86
	@ cp grub.cfg iso_root/boot/grub/grub.cfg
	@ cp dist/x86/kernel.bin iso_root/boot/kernel.bin
	@ grub-mkrescue iso_root -o dist/x86/clave.iso
	@ rm -rf iso_root

clean:
	@ rm -rf dist iso_root kernel/build