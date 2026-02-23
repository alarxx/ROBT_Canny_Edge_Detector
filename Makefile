# target [target2 ...]: [prerequisites ...]
	# [command1
	#  command2
	# ........]

# Phony targets are not files
.PHONY: \
	run \
	Tensor-library

help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... run  		- Build and Run"
	@echo "... Tensor-library 	- Build and Install Tensor-library"

run:
# 	cmake -S . -B build
# 	cmake --build ./build
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
	cmake --build build -j
	./build/Canny


clean:
	rm -rf build
	rm -rf Tensor-library/build/

Tensor-library:
	cd Tensor-library && make cmake-install
