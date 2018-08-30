include ../../config.mk

TARGET = z80-disasm

build:	$(TARGET)
    
$(TARGET):
	make -C $(BUILD_DIR)/apps/$(TARGET)	

prepare:
	mkdir -p $(BUILD_DIR)/apps/$(TARGET) && \
	cd $(BUILD_DIR)/apps/$(TARGET) && cmake $(CWD)

install:
	make -C $(BUILD_DIR)/apps/$(TARGET)	install

clean:
	make -C $(BUILD_DIR)/apps/$(TARGET)	 clean

run: build
	$(BUILD_DIR)/apps/$(TARGET)/$(TARGET) $(BUILD_DIR)/../dumps/zx_spectrum/tests/TEST48.BIN

run2: build
	$(BUILD_DIR)/apps/$(TARGET)/$(TARGET) $(BUILD_DIR)/../dumps/zx_spectrum/tests/TEST48K.rom
#	$(BUILD_DIR)/apps/$(TARGET)/$(TARGET) $(BUILD_DIR)/../dumps/mips.bin 

run_dbg: build
	gdb --args $(BUILD_DIR)/apps/$(TARGET)/$(TARGET)  $(BUILD_DIR)/../dumps/zx_spectrum/48.bin 
