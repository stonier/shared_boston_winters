# If using the usual binary location
# DRAKE_DIR=/opt/drake/lib/cmake/drake
# If building this inside the delphyne workspace
DRAKE_DIR=../../install/lib/cmake/drake

all: 
	mkdir -p build
	cd build && cmake -Ddrake_DIR=${DRAKE_DIR} .. || exit $$?
	cd build && make -j$(getconf _NPROCESSORS_ONLN) install || exit $$?	

help:
	@echo ""
	@echo "Valid Targets:"
	@echo ""
	@echo "    all       : cmake/make/install"
	@echo "    clean     : clean all cmake project build and install directories"
	@echo ""

clean:
	rm -rf build install

.PHONY:  clean
