# C++ Program construction for Scientic Computing
## Assignment 1

**Authors:**
- Andres Alam Sánchez
- Leonardo Lüder

This program implements the Adaptive Simpson Integration (ASI) algorithm,
which approximates a definite integral of a function by recursively applying Simpson’s rule to subdivided intervals.



## How to run

The project can be run from any CMake compatible IDE through `CMakeLists.txt`. Otherwise, it can be run manually with the following steps:

1. From the root folder, configure the CMake project for the first time
```bash
cmake -S . -B build
```
2. Build project files
```
cmake --build build
```
3. Run tests
```
ctest --test-dir build
```
or run the main executable
```
./build/main
```