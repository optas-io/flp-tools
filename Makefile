.PHONY: build
.PHONY: test

build:
	@cmake --build build
	@cp build/compile_commands.json compile_commands.json

test: build
	@build/test/flptools_test

configure:
	@cmake -S . -B build

clean:
	@rm -rf build
	@rm -f compile_commands.json
