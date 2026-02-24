# Canny Edge Detector

Full program: <br>
274'414'972ns - Custom (3FPS) x44 <br>
106'746'999ns - Custom without blurring (9FPS) x17 <br>
14'866'071ns - Custom without blurring -O3 optimization (64FPS) x2.5 <br>
15'684'256ns - OpenCV-Python high (64FPS) <br>
7'670'081ns - OpenCV-Python low (130FPS) <br>
6'143'235ns - OpenCV (162FPS) <br>

Without imread(): <br>
10'284'509ns - Best Custom x5 <br>
2'409'686ns - Best OpenCV <br>

![Canny(Lenna)](https://github.com/alarxx/Canny_Edge_Detector/blob/master/images/steps/hysterisis.png)

## Git Submodules

```sh
git submodule add -b c++mappings git@github.com:alarxx/Tensor-library.git
git submodule add -b 4.x git@github.com:opencv/opencv.git
```

Set branches:
```sh
git submodule set-branch -b c++mappings Tensor-library
git submodule set-branch -b 4.x opencv
```

Initialize and update submodules to recorded commits:
```sh
git submodule update --init --recursive
```

Merge updates, fetching new commits:
```sh
git submodule update --remote [--recursive]
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

```sh
make install-opencv
```

[Build and Install OpenCV](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html) <br>
OpenCV example: [OpenCV with CMake](https://docs.opencv.org/4.x/db/df5/tutorial_linux_gcc_cmake.html) <br>

----

## Build and Install Tensor-library

[Tensor-library](https://github.com/alarxx/Tensor-library)

Execute either:
```sh
cd Tensor-library && make cmake-install
```
or
```sh
make install-tensor-library
```

---

## Build and Run

```sh
make run
# cmake -S . -B build
# cmake --build ./build
# ./build/Canny
```

---

## System

- OS: Debian 12 (Bookworm)
- Compiler: GCC 12.2.0
- C++ standard: C++20
- CMake: 3.25.1
- Ninja: 1.11.1

---

## References

- Wikipedia: https://en.wikipedia.org/wiki/Canny_edge_detector
- IEEE: https://ieeexplore.ieee.org/document/4767851
- Computerphile (Youtube) - Canny Edge Detector. https://www.youtube.com/watch?v=sRFM5IEqR2w
- Step by step in Python. https://medium.com/data-science/canny-edge-detection-step-by-step-in-python-computer-vision-b49c3a2d8123

