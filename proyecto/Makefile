.PHONY: all build run clean

all: build run

build:
	@mkdir -p build
	@cd src/vuelos && qmake vuelos.pro && $(MAKE)

run:
	@./build/vuelos

clean:
	@rm -rf build/*
