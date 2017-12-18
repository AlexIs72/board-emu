include ../../config.mk

TARGET = libemu_core

build: $(TARGET)
    
$(TARGET):
	make -C $(BUILD_DIR)/lib/$(TARGET)

install:
	make -C $(BUILD_DIR)/lib/$(TARGET) install

clean:
	make -C $(BUILD_DIR)/lib/$(TARGET) clean
