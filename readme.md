# Human Obstacle Detector - ACME
[![Build Status](https://travis-ci.org/cunninghamr/HumanObstacleDetector.svg?branch=master)](https://travis-ci.org/cunninghamr/HumanObstacleDetector)
[![Coverage Status](https://coveralls.io/repos/github/cunninghamr/HumanObstacleDetector/badge.svg?branch=master)](https://coveralls.io/github/cunninghamr/HumanObstacleDetector?branch=master)
[![License](https://img.shields.io/badge/License-BSD%202--Clause-orange.svg)](https://opensource.org/licenses/BSD-2-Clause)
---

## Overview

Robotics is a rapidly growing field, and as the technology advances new robots are created to serve
different purposes in commercial and military applications. As the interaction between robots and humans has increased exponentially over the past years, one big concern which has emerged with this development is human safety in environments with the presence of robots. Robots are responsible for many accidents involving humans and because of that, part of the population has aversion to the robotics field. This strong dislike prevents the growing of robotics field and consequently limits the development of companies involved in this area. This project presents a software solution to minimize accidents between robots and humans, where the module will be using computer vision tools in order to make robots recognize humans and identify their location. The most significant output of the module will be the location/distance of the person, where this will allow for any mobile robot to accurately identify human obstacles to later provide this information/data to other modules in the system to be able to either avoid or stop the robot from colliding with human obstacles.

The porpose of the project is to identify humans and provide their real world location in order for the robot to avoid accidents in its environment. In order to achieve this goal, Suport Vector Machines and Histogram of Oriented Gradients are used to identify humans in the images provided by the camera. To implement the techniques previously mentioned, the team decided to use the OpenCV library. The camera intrinsic and extrinsic parametes and the pixel location of the human in the image are used to properly calculate the real world position of the human. The project implementation is mainly composed by 4 classes which are Data, Detection, Locator and ProgramOptions. The ProgramOption class reads arguments from the command line, the Data class loads all the images where humans should be identified, the Detection class is responsable for the  identification of the human using OpenCv SVM and Hogdescriptors and provide the bouding box for the locator class, and the Locator class provides the real world location based on the image pixel location.

The program starts by loading all the images of the desired diretory. Once all the images are loaded the OpenCV trained SVM is used to classify humans and the HOGDescriptor is used to check the presence of humans. If a human is detected,a bounding box with the location of the human is returned.
<p align="center">
<img src="https://github.com/cunninghamr/HumanObstacleDetector/blob/master/app/images/Readme/pic_read.png">
</p>


Once the bounding box information is ready, it is possible to calculate the pixel position of the human and with the pixel position using the inverse of the homography matrix , which is the inverse of the multiplication of the camera intrinsic parameters and the extrinsic prameters we can find the 3d real world location.
In the demo the values in feets are shown as in the follwing image

<p align="center">
<img src="https://github.com/cunninghamr/HumanObstacleDetector/blob/master/app/images/Readme/humanDetection.jpg">
</p>

## Personnel
Andre Gomes - Graduated in computer engineering at Uniceub in Brazil.

Ryan Cunningham - Works for Booz Allen Hamilton as a full-stack software engineer. Graduated with a Computer Science degree from UMBC in 2013.

Pablo - Graduated with a B.S. in Mechanical Engineering from UMCP in 2017. Currently pursuing a M. Eng. in Robotics at UMCP. Highly interested in Machine Learning and Autonomous Robots. 

## License

BSD License
Copyright 2019 Ryan Cunningham, Andre Gomes, Pablo Sanhueza

```
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

```


## AIP Google Sheet

https://drive.google.com/file/d/1tollRMMNQe3B8FCTQr8AEhi9hTGRpPKR/view?usp=sharing


## Review of Iteration 1 Plan

https://docs.google.com/document/d/1hpV3EcaRyg9J7VAmwT8K__PkkRvtQr3ay-QYJ0cU4dg/edit?usp=sharing


## Review of Iteration 2 Plan

https://drive.google.com/file/d/1NWiB6Zz3JGev2qfO4f3q6IjTkykSAXTG/view?usp=sharing


## Dependencies

### OpenCV

Install OpenCV 3.2.0 with the following terminal commands.

Updating Ubuntu
```
sudo apt-get update
 
sudo apt-get upgrade
```
Install Dencencies
```
sudo apt-get install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
 
sudo apt-get install python3.5-dev python3-numpy libtbb2 libtbb-dev
 
sudo apt-get install libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev

```
Get OpenCV
```
sudo -s
 
cd /opt
 
git clone https://github.com/Itseez/opencv.git
 
git clone https://github.com/Itseez/opencv_contrib.git
```
Build and Install OpenCV
```
cd opencv
 
mkdir release
 
cd release
 
 cmake -D BUILD_TIFF=ON -D WITH_CUDA=OFF -D ENABLE_AVX=OFF -D WITH_OPENGL=OFF -D WITH_OPENCL=OFF -D WITH_IPP=OFF -D WITH_TBB=ON -D BUILD_TBB=ON -D WITH_EIGEN=OFF -D WITH_V4L=OFF -D WITH_VTK=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules /opt/opencv/
 
make -j4
 
make install
 
 ldconfig
 
 exit
 
 cd ~
```
Check if OpenCV is installed
```
pkg-config --modversion opencv
```
### Boost

Install Boost with the following terminal commands.
```
sudo apt-get install libboost-all-dev
```


## How to build
```
git clone --recursive https://github.com/cunninghamr/HumanObstacleDetector
cd <path to repository>
mkdir build
cd build
cmake ..
make
```

## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.


## How to run demo
```
cd <build inside the cloned folder>
Run program: ./app/shell-app -p ../app/images/positive/ -n ../app/images/negative/
```

## How to run tests
```
cd <build inside the cloned folder>
Run tests: ./test/cpp-test
```


## Known Issues/Bugs

For some images, a single detected human may have multiple bounding boxes


### How to Generate Doxygen Documentation 

How to install Doxygen:
```
sudo apt-get install doxygen
```

Inside the cloned Directory, enter the following terminal commands.
```
 doxygen Doxyfile
```

Opening Doxygen Documentation in Firefox
```
 cd Docs
 cd html
 firefox index.html
```


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
