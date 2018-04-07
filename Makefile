all: 
	mkdir -p build
	cd build && cmake .. || exit $$?
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
