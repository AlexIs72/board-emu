include ../../config.mk

TARGET = mips-disasm

build:	$(TARGET)
    
$(TARGET):
	make -C $(BUILD_DIR)/apps/$(TARGET)	

install:
	make -C $(BUILD_DIR)/apps/$(TARGET)	install

clean:
	make -C $(BUILD_DIR)/apps/$(TARGET)	 clean

run: build
	$(BUILD_DIR)/apps/$(TARGET)/$(TARGET) $(BUILD_DIR)/../dumps/mips.bin 

run_dbg: build
	gdb --args $(BUILD_DIR)/apps/$(TARGET)/$(TARGET)  $(BUILD_DIR)/../dumps/mips.bin 
