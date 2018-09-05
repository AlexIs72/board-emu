all:
	@for target in $(TARGETS); do printf "$(CYAN)$(BRIGHT)\n\n   build target: $${target}\n\n$(NORMAL)"; make -C $${target} || exit 1; done

install:
	@for target in $(TARGETS); do printf "$(CYAN)$(BRIGHT)\n\n   install target: $${target}\n\n$(NORMAL)"; make -C $${target} install || exit 1; done

clean:
	@for target in $(TARGETS); do printf "$(CYAN)$(BRIGHT)\n\n   clean target: $${target}\n\n$(NORMAL)"; make -C $${target} clean || exit 1; done
