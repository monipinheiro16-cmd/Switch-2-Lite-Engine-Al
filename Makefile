.PHONY: all clean test

all:
	mkdir -p build && cd build && cmake .. && make

test: all
	cd build && ctest --output-on-failure

clean:
	rm -rf build
