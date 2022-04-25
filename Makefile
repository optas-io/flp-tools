.PHONY: build
.PHONY: test

build: configure
	@cmake --build build
	@cp build/compile_commands.json compile_commands.json

test: build
	@cd build && ctest

test@%: build
	@build/test/$*_test

configure: build/CMakeCache.txt
	@#

build/CMakeCache.txt:
	@cmake -S . -B build

clean:
	@rm -rf build
	@rm -f compile_commands.json
