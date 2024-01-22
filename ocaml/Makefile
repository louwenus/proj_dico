SOURCES=
SOURCES+=main.ml


.PHONY: all help clean mpropper

all: correct_ml

help:
	@echo "Makefile help"
	@echo "    make             Compiles and links the program (stripped)"
	@echo "    make mpropper    Cleans compilation files and executable"
	@echo "    make help        Displays this help"

correct_ml: build $(SOURCES)
	cp $(SOURCES) build/
	cd build; \
	ocamlopt -o ../correct_ml $(SOURCES)
	cp correct_ml ../correct_ml
	@echo "La compilation a réussie! Le programme s'apelle correct_ml, lancez le en terminal avec la commande ./correct_ml"

build:
	mkdir build
clean:
	rm -rf build
		
mpropper: clean
	-rm correct_ml
	-rm ../correct_ml

