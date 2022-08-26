
MAKEFLAGS += --no-print-directory

TOOLDIRS := $(filter-out tools/agbcc tools/binutils,$(wildcard tools/*))

.PHONY: all $(TOOLDIRS)

all: $(TOOLDIRS) tools/agbcc

$(TOOLDIRS):
	@$(MAKE) -C $@

tools/agbcc: subrepos/agbcc/agbcc
	cd subrepos/agbcc; ./install.sh ../..

subrepos/agbcc/agbcc:
	cd subrepos/agbcc; ./build.sh
