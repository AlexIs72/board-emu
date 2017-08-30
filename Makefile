PWD=$(shell pwd)
BUILD_DIR=build
CONFIG_MK=config.mk
TARGETS=lib apps

all: $(TARGETS)

prepare: $(BUILD_DIR) $(CONFIG_MK)
	@echo "build Makefile(s)..."
	@for target in $(TARGETS); do cd $(PWD)/$(BUILD_DIR)/$${target} && cmake $(PWD)/$${target}; done
#	@for target in $(TARGETS); do make  -C $${target} BUILD_DIR=$(PWD)/build prepare; done

$(BUILD_DIR):
	@echo "creating build dir(s)..."
	@for target in $(TARGETS); do mkdir -p $(PWD)/$(BUILD_DIR)/$${target}; done

$(CONFIG_MK):
	@echo "build $(CONFIG_MK)..." 
	@echo "# Generated automatically - do not edit!" > $(CONFIG_MK)
	@echo "include $(PWD)/build.mk/colors.mk" >> $(CONFIG_MK)
	@echo "" >> $(CONFIG_MK)
	@echo "export BUILD_DIR=$(BUILD_DIR)" >> $(CONFIG_MK)

$(TARGETS):
	@echo "build target(s)..."
	@make -C $@

clean:
	@rm -rf build

.PHONY:	$(TARGETS)