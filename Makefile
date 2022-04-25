.PHONY: build
.PHONY: test

build:
	@cmake --build build
	@cp build/compile_commands.json compile_commands.json

test:
	@cd build && ctest --build-and-test

test@%: build
	@build/test/$*_test

configure:
	@cmake -S . -B build

clean:
	@rm -rf build
	@rm -f compile_commands.json
