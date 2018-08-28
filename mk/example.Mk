EXAMPLE_OBJ= \
  src/example/main.o

EXAMPLE_BIN=$(BIN_DIR)/example

$(EXAMPLE_BIN): $(EXAMPLE_OBJ)
	$(CXX) -o $@ $(LFLAGS) $<

src/%.o: src/%.cpp
	$(CXX) -c -o $@ $(CFLAGS) $(CXXFLAGS) $<
	@sh ./depends.sh depends.Mk $<
