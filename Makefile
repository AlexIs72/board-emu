CWD:=$(shell pwd)
BUILD_DIR=$(CWD)/build
CONFIG_MK=config.mk
TARGETS=lib apps

all: $(BUILD_DIR) $(CONFIG_MK) $(TARGETS)

prepare: $(BUILD_DIR) $(CONFIG_MK)
	@echo "build Makefile(s)..."
	@for target in $(TARGETS); do cd $(BUILD_DIR)/$${target} && cmake $(CWD)/$${target}; done
#	@for target in $(TARGETS); do make  -C $${target} BUILD_DIR=$(PWD)/build prepare; done

$(BUILD_DIR): 
	@echo "creating build dir(s)..."
	@for target in $(TARGETS); do mkdir -p $(BUILD_DIR)/$${target}; done

$(CONFIG_MK):
	@echo "build $(CONFIG_MK)..." 
	@echo "# Generated automatically - do not edit!" > $(CONFIG_MK)
	@echo "include $(CWD)/build.mk/colors.mk" >> $(CONFIG_MK)
	@echo "" >> $(CONFIG_MK)
	@echo export BASE_DIR=$(shell pwd) >> $(CONFIG_MK)
	@echo export CWD='$$(shell pwd)' >> $(CONFIG_MK)
	@echo export BUILD_DIR='$$(BASE_DIR)'/build >> $(CONFIG_MK)
	@echo export BUILD_APPS_DIR='$$(BUILD_DIR)'/apps >> $(CONFIG_MK)

$(TARGETS):
	@echo "build target(s)..."
	@make -C $@ || exit 1

clean:
	@rm -rf build

.PHONY:	$(TARGETS)