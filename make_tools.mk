# This controls building executables in the `tools` folder.
# Can be invoked through the `Makefile` or standalone.

MAKEFLAGS += --no-print-directory

# Inclusive list. If you don't want a tool to be built, don't add it here.
TOOLS_DIR := tools
TOOL_NAMES := aif2pcm bin2c gbafix gbagfx jsonproc mapjson mid2agb preproc ramscrgen rsfont scaninc

TOOLDIRS := $(TOOL_NAMES:%=$(TOOLS_DIR)/%)

# Tool making doesnt require a pokeemerald dependency scan.
RULES_NO_SCAN += tools check-tools clean-tools $(TOOLDIRS)
.PHONY: $(RULES_NO_SCAN)

tools: $(TOOLDIRS) tools/agbcc

$(TOOLDIRS):
	@$(MAKE) -C $@

clean-tools:
	@$(foreach tooldir,$(TOOLDIRS),$(MAKE) clean -C $(tooldir);)
	@$(MAKE) -C subrepos/agbcc/gcc clean
	@$(MAKE) -C subrepos/agbcc/gcc_arm clean
	@$(MAKE) -C subrepos/agbcc/libgcc clean
	@$(MAKE) -C subrepos/agbcc/libc clean
	rm -rf tools/agbcc
	rm -f subrepos/agbcc/agbcc
	rm -f subrepos/agbcc/old_agbcc
	rm -f subrepos/agbcc/agbcc_arm
	rm -f subrepos/agbcc/libgcc.a
	rm -f subrepos/agbcc/libc.a
	rm -rf subrepos/flips/obj
	rm -f subrepos/flips/flips

tools/agbcc: subrepos/agbcc/agbcc
	cd subrepos/agbcc; ./install.sh ../..

subrepos/agbcc/agbcc:
	cd subrepos/agbcc; ./build.sh

subrepos/pokeemerald/tools/agbcc: subrepos/agbcc/agbcc
	cd subrepos/agbcc; ./install.sh ../pokeemerald

subrepos/berry-fix/tools/agbcc: subrepos/agbcc/agbcc
	cd subrepos/agbcc; ./install.sh ../berry-fix

subrepos/flips/flips:
	cd subrepos/flips; ./make.sh
