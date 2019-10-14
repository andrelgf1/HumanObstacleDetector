# Human Obstacle Detector - ACME
[![Build Status](https://travis-ci.org/cunninghamr/cpp-boilerplate.svg?branch=master)](https://travis-ci.org/cunninghamr/cpp-boilerplate)
[![Coverage Status](https://coveralls.io/repos/github/cunninghamr/cpp-boilerplate/badge.svg?branch=master)](https://coveralls.io/github/cunninghamr/cpp-boilerplate?branch=master)
---

## Overview

This project will utilize OpenCV functions for the implementation of different classes to detect humans as obstacles. Here, you will see the utilization of Histogram of Oriented Gradients (HOG) and Support Vector Machines (SVM) to accomplish such task.

You will also see the usage of the AIP process and pair programming. In addition you will find different iterations of UML diagrams as the design of the source codes progress. 

Implementation:

- TDD
- OOP Principles
- C++11/14
- cppcheck
- Google style guide with cpplint


Testing:

- Unit Tests
- Test Coverage with Coveralls
- Passing tests on Travis


## AIP Google Sheet

https://drive.google.com/file/d/1tollRMMNQe3B8FCTQr8AEhi9hTGRpPKR/view?usp=sharing


## Review of Iteration 1 Plan

https://docs.google.com/document/d/1hpV3EcaRyg9J7VAmwT8K__PkkRvtQr3ay-QYJ0cU4dg/edit?usp=sharing


## Standard install via command-line
```
git clone --recursive https://github.com/cunninghamr/HumanObstacleDetector
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Dependencies

Stub to be completed in Iteration 2.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/cunninghamr/cpp-boilerplate
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../cpp-boilerplate/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Test

Stub to be completed in Iteration 2.

## Run/Demo

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)

## Known Issues/Bugs

Stub to be completed in Iteration 2.

## Debug


1. Set breakpoint in source file (i.e. double click in the left margin on the line you want 
the program to break).

2. In Eclipse, right click on the boilerplate-eclipse in Project Explorer, select Debug As -> 
Local C/C++ Application, choose the binaries to run (e.g. shell-app).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in 
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++ 
perspetive view (or Windows->Perspective->Open Perspective->C/C++).


## Plugins

- CppChEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.


- Google C++ Sytle

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right click on the source code or folder in 
    Project Explorer and choose Source -> Format

[reference-id-for-eclipse-cpp-google-style]: https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-cpp-google-style.xml

- Git

    It is possible to manage version control through Eclipse and the git plugin, but it typically requires creating another project. If you're interested in this, try it out yourself and contact me on Canvas.
