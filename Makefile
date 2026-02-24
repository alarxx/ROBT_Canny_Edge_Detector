# target [target2 ...]: [prerequisites ...]
	# [command1
	#  command2
	# ........]

# Phony targets are not files
.PHONY: \
	run \
	clean \
	submodules \
	install-tensor-library \
	install-opencv \
	clean-opencv

help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... run  			- Build and Run"
	@echo "... clean  			- Clean"
	@echo "... submodules  			- Fetch Git Submodules"
	@echo "... install-tensor-library 	- Build and Install Tensor-library"
	@echo "... install-opencv 		- Build and Install OpenCV"
	@echo "... clean-opencv 		- Clean OpenCV"

run:
# 	cmake -S . -B build
# 	cmake --build ./build
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
	cmake --build build -j
	./build/Canny

clean:
	rm -rf build
	rm -rf Tensor-library/build/

submodules:
	git submodule update --init --recursive

install-tensor-library:
	cd Tensor-library && make cmake-install

install-opencv:
	# Build OpenCV with Ninja:
	cd opencv && cmake -S . -B build -G Ninja -DWITH_QT=ON -DWITH_GTK=OFF
	cd opencv/build && ninja
	# Install OpenCV
	cd opencv/build && su -c "ninja install"

clean-opencv:
	rm -rf opencv/build
	# doesn't clean from system
