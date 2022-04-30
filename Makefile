.PHONY: build
.PHONY: test

build: configure
	@cmake --build build
	@cp build/compile_commands.json compile_commands.json

test: build
	@echo " "
	@cd build && ctest

test@%: build
	@echo " "
	@build/tests/$*_test

configure: build/CMakeCache.txt
	@#

build/CMakeCache.txt:
	@cmake -S . -B build

image@%:
	@docker-compose -f docker/$*/docker-compose.build.yml build

docker-test:
	@docker-compose -f docker/compose/test/docker-compose.yml up

clean:
	@rm -rf build
	@rm -f compile_commands.json
