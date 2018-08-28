CC=cc
CXX=c++
CFLAGS=-Iinclude
CXXFLAGS=
LFLAGS=-g

BIN_DIR=bin

.PHONY: bootstrap
bootstrap:
	@$(MAKE) all

include mk/example.Mk
-include depends.Mk

.PHONY: all
all: $(BIN_DIR) $(EXAMPLE_BIN)

.PHONY: help
help:
	@echo ""
	@echo "all     - Build entire project"
	@echo "clean   - Clean up project"
	@echo "clean_o - Clean up just the generated objects"
	@echo "help    - This help menu"
	@echo ""

$(BIN_DIR):
	mkdir $@

.PHONY: clean
clean:
	@$(MAKE) clean_o
	rm -f $(EXAMPLE_BIN)
	rm -rf $(BIN_DIR)

.PHONY: clean_o
clean_o:
	rm -f $(EXAMPLE_OBJ)
	rm -f depends.Mk
