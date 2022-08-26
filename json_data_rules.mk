# JSON files are run through jsonproc, which is a tool that converts JSON data to an output file
# based on an Inja template. https://github.com/pantor/inja

AUTO_GEN_TARGETS += $(DATA_SRC_SUBDIR)/wild_encounters_rs.h
$(DATA_SRC_SUBDIR)/wild_encounters_rs.h: $(DATA_SRC_SUBDIR)/wild_encounters_rs.json $(DATA_SRC_SUBDIR)/wild_encounters_rs.json.txt
	$(JSONPROC) $^ $@


AUTO_GEN_TARGETS += $(DATA_SRC_SUBDIR)/wild_encounters_frlg.h
$(DATA_SRC_SUBDIR)/wild_encounters_frlg.h: $(DATA_SRC_SUBDIR)/wild_encounters_frlg.json $(DATA_SRC_SUBDIR)/wild_encounters_frlg.json.txt
	$(JSONPROC) $^ $@


AUTO_GEN_TARGETS += $(DATA_SRC_SUBDIR)/wild_encounters_e.h
$(DATA_SRC_SUBDIR)/wild_encounters_e.h: $(DATA_SRC_SUBDIR)/wild_encounters_e.json $(DATA_SRC_SUBDIR)/wild_encounters_e.json.txt
	$(JSONPROC) $^ $@


AUTO_GEN_TARGETS += $(DATA_SRC_SUBDIR)/wild_encounters.h
$(DATA_SRC_SUBDIR)/wild_encounters.h: $(DATA_SRC_SUBDIR)/wild_encounters.json $(DATA_SRC_SUBDIR)/wild_encounters.json.txt
	$(JSONPROC) $^ $@

$(C_BUILDDIR)/wild_encounter.o: c_dep += $(DATA_SRC_SUBDIR)/wild_encounters.h
	c_dep += $(DATA_SRC_SUBDIR)/wild_encounters_rs.h
	c_dep += $(DATA_SRC_SUBDIR)/wild_encounters_frlg.h
	c_dep += $(DATA_SRC_SUBDIR)/wild_encounters_e.h
