KERNEL_SOURCE_FILES := $(shell find kernel -name *.c)
KERNEL_OBJECT_FILES := $(patsubst kernel/%.c, build/kernel/%_c.o, $(KERNEL_SOURCE_FILES))

x86_C_SOURCE_FILES := $(shell find arch/x86 -name *.c)
x86_C_OBJECT_FILES := $(patsubst arch/x86/%.c, build/arch/x86/%_c.o, $(x86_C_SOURCE_FILES))

x86_ASM_SOURCE_FILES := $(shell find arch/x86 -name *.asm)
x86_ASM_OBJECT_FILES := $(patsubst arch/x86/%.asm, build/arch/x86/%_asm.o, $(x86_ASM_SOURCE_FILES))

x86_OBJECT_FILES := $(x86_C_OBJECT_FILES) $(x86_ASM_OBJECT_FILES)

$(KERNEL_OBJECT_FILES): build/kernel/%_c.o : kernel/%.c
	@ mkdir -p $(dir $@)
	@ i686-elf-gcc -ffreestanding -O2 -Wall -Wextra -I include -c $(patsubst build/kernel/%_c.o, kernel/%.c, $@) -o $@

$(x86_C_OBJECT_FILES): build/arch/x86/%_c.o : arch/x86/%.c
	@ mkdir -p $(dir $@)
	@ i686-elf-gcc -ffreestanding -O2 -Wall -Wextra -I include -c $(patsubst build/arch/x86/%_c.o, arch/x86/%.c, $@) -o $@

$(x86_ASM_OBJECT_FILES): build/arch/x86/%_asm.o : arch/x86/%.asm
	@ mkdir -p $(dir $@)
	@ nasm -f elf32 $(patsubst build/arch/x86/%_asm.o, arch/x86/%.asm, $@) -o $@

.PHONY: build-x86-kernel
build-x86-kernel: $(KERNEL_OBJECT_FILES) $(x86_OBJECT_FILES)
	@ mkdir -p dist/x86
	@ i686-elf-gcc -ffreestanding -O2 -nostdlib -lgcc -T arch/x86/linker.ld -o dist/x86/kernel.bin $(KERNEL_OBJECT_FILES) $(x86_OBJECT_FILES)