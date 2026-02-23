# Canny Edge Detector

## Git Submodules

```sh
git submodule add git@github.com:alarxx/Tensor-library.git
git submodule add git@github.com:opencv/opencv.git
```

Initialize and update submodules to recorded commits:
```sh
git submodule update --init --recursive
```

Merge updates:
```sh
git submodule update --remote
```

---

Install Ninja build system:
```sh
apt install ninja-build
ninja --version
```

Install Qt GUI:
```sh
apt install -y qtcreator qtbase5-dev qt5-qmake cmake
```

---

## Build and Install OpenCV

[Build and Install OpenCV](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html):
```sh
cd ./opencv
# git checkout 4.x
```

Build OpenCV with Ninja:
```sh
cmake -S . -B build -G Ninja -DWITH_QT=ON -DWITH_GTK=OFF
cd ./build
ninja
```

Install OpenCV:
```sh
# cd ./build
su -c "ninja install"
```

OpenCV example: [OpenCV with CMake](https://docs.opencv.org/4.x/db/df5/tutorial_linux_gcc_cmake.html)

----

## Build and Install Tensor-library

```sh
make Tensor-library
# cd Tensor-library && make cmake-install
```

## Build and Run

```sh
make run
# cmake -S . -B build
# cmake --build ./build
# ./build/Canny
```
