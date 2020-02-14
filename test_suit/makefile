DIRECTORY := $(wildcard */)

test: constructor_test read_test write_test
	@$(MAKE) -C $< bin/program test clean
	@$(MAKE) -C read_test all test clean
	@$(MAKE) -C write_test all test clean

	
