# Space Invader Game
This is a simplified shoot game using C++ and raylib. \
<img src="https://github.com/xuezihe/SpaceInvaderGame/blob/master/resources/game.gif" width="400" height="300" />


# Dependencies for Running Locally
Highly recommand using windows system 

* premake (included)
* cmake >= 3.16.3
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.2 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 9.0.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same instructions as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* raylib >= 4.0.0
    * All OSes: [click here for installation instructions](https://github.com/raysan5/raylib)


# Play this game directly

You can download the latest file from release page https://github.com/xuezihe/SpaceInvaderGame/releases/tag/release.

# Generate the project

For windows users, there are two batch files you can use depending on what compiler you are using. For linux users you can simply use a terminal.
Only do ONE of these options depending on your compiler and platform.
## Windows Users
Visual Studio users should run

    premake-VisualStudio.bat
	
This will generate a Visual Studio project.
	
## Linux users
cd to the game folder and run

    ./premake5 gmake2

This will generate a makefile for you.

## macOS users
cd to the game folder and run

    ./premake5.osx gmake2
	
This will generate a makefile for you.

# Build this game

Only do ONE of these options depending on your compiler and platform.

## Windows Users

Double click the .sln file that was generated in the folder. From here you can build the project as normal.

## MinGW-w64 Users

Open your compiler terminal (w64devkit if you are using it), change to the game folder and type

```
make
```
	
## Linux/macOS users
Open your terminal, change to the game folder and type.

```
make
```
	

This will build your game

# How to Play
P: Pause the Game

WASD: Move the space ship

R: Reload the weapon

SPACE: Shoot

ENTER:Restart game


# Wave Amount
three waves totally.


# Project Structure
<img src="https://github.com/xuezihe/SpaceInvaderGame/blob/master/resources/SpaceInvaderStructure.drawio.png" width="500" height="600" />

# rubric point addressed
## Loops, Functions, I/O
  - [x] The project demonstrates an understanding of C++ functions and control structures.
  - [x] The project reads data from a file and process the data, or the program writes data to a file.
  - [X] The project accepts user input and processes the input.
## Object Oriented Programming
  - [X] The project uses Object Oriented Programming techniques.
  - [X] Classes use appropriate access specifiers for class members.
  - [X] Class constructors utilize member initialization lists.
  - [X] Classes abstract implementation details from their interfaces.
## Memory Management
  - [X] The project makes use of references in function declarations.
  - [X] The project uses destructors appropriately.
  - [X] The project follows the Rule of 5.
