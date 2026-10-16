# C++ Practice Assignments

This repository contains simple C++ practice programs for learning basic input/output and class usage.

## Files

- `assignment1.cpp` - A basic "Hello, World!" program.
- `assignment2.cpp` - A class-based program that reads a student PRN and name, then displays the values.
- `assignment3.cpp` - A similar class-based program with member functions defined outside the class.

> Note: `assignment2` and `assignment3` appear to be compiled executables from the source files.

## Build Instructions

From the repository root, use `g++` to compile each source file:

```bash
g++ assignment1.cpp -o assignment1
g++ assignment2.cpp -o assignment2
g++ assignment3.cpp -o assignment3
```

## Run Instructions

Execute the compiled programs from the repository root:

```bash
./assignment1
./assignment2
./assignment3
```

## Notes

- `assignment2.cpp` uses a class `B` with inline member functions.
- `assignment3.cpp` defines the same class structure but implements member functions outside the class.
- This repository is suitable for C++ beginners practicing basic class and I/O syntax.
