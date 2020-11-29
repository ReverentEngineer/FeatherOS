PATH := /opt/crosstools/bin:$(PATH)
CXX := i686-elf-g++
AS := i686-elf-as

ASFLAGS :=
CXXFLAGS := -ffreestanding -O0 -ggdb -Wall -Wextra -fno-exceptions -fno-rtti -Iinclude
LDFLAGS := -ffreestanding -O2 -nostdlib 

CXX_SOURCES := src/boot/kernel.cc src/mm/pmm.cc src/io/terminal.cc
CASM_SOURCES := src/boot/boot.s

all: dist/featheros.bin
.PHONY: all

iso: dist/featheros.iso
.PHONY: iso

ifneq ($(ARCH),x86)
include x86.mk
else ifeq ($(ARCH),)
$(warning Defaulting to x86)
include x86.mk
else
$(error Unsupported architecture: $(ARCH)))
endif

ASM_OBJECTS := $(patsubst src/%.s,src/%.o,$(ASM_SOURCES))
CXX_OBJECTS := $(patsubst src/%.cc,src/%.o,$(CXX_SOURCES))
OBJECTS := $(ASM_OBJECTS) $(CXX_OBJECTS) $(C_OBJECTS)

src/%.o: src/%.s objs
	$(AS) $(ASFLAGS) $< -o $@

src/%.o: src/%.cc objs
	$(CXX) -c  $< -o $@ $(CXXFLAGS)

dist:
	mkdir dist

dist/featheros.bin: $(OBJECTS) dist
	$(CXX) -T linker.ld -o $@ $(LDFLAGS) $(OBJECTS)

dist/featheros.iso: dist/featheros.bin
	./scripts/make_iso.sh $< dist

clean:
	rm -f $(OBJECTS)
	rm -rf dist
.PHONY: clean
