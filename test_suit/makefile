DIRECTORY := $(wildcard */)

test: constructor_test
	@$(MAKE) -C $<
	@$(MAKE) -C $< test
	@$(MAKE) -C $< clean
