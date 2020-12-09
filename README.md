# sportgems

Sportgems finds the valuable gems 💎 in your tracked sport 🚴 activity!


## What is it?
Sportgems is a tiny command line interface (CLI) which lets you efficiently parse your 
activity data. It will search and find your fastest sections. It will determine the start,
end and average speed of a configurable set of fastest sections, for example the fastest
1km, 2km and 10km. 


## How to use it?
In general sportgems is used with `gpx` files like this
```
./sportgems path/to/file.gpx
```
with the resulting output
```
Hi 👋 from sportgems! Will search for 💎 in ../test/data/running.gpx
Input track is 10.3661km long - searching for fastest 1km, 2km, 3km, 5km, 10km.

========================== Results ==========================
Found the following gems: 
💎 Fastest 1km: start: 190, end: 492, velocity: 6.68741 m/s
💎 Fastest 2km: start: 190, end: 1148, velocity: 4.20961 m/s
💎 Fastest 3km: start: 190, end: 1799, velocity: 3.75796 m/s
💎 Fastest 5km: start: 190, end: 3029, velocity: 3.54729 m/s
💎 Fastest 10km: start: 190, end: 6140, velocity: 3.38448 m/s
```

## Installation
In order to do so, you need to clone this repo and build it from sources. How to do this
is described in depth in the following.

First clone the repo (using the `--recurse-submodules` option to include [gtest](https://github.com/google/googletest/)
for testing)
```
git clone git@github.com:fgebhart/sportgems.git --recurse-submodules
cd sportgems
```

Create a build directory and compile the source code
```
mkdir build
cd build
cmake ..
make
```

Inside the build directory you'll find the compiled executable `sportgems`. In order to display
the valid options of the CLI run
```
./sportgems --help

Usage: ./sportgems path/to/file.gpx

💎 Sportgems is a CLI for finding the fastest sections in your GPX tracks 💎

In the default configuration sportgems will search for the fastest:
1km, 2km, 3km, 5km, 10km and 20km

Optional arguments are:
--debug        Enables debugging and makes output more verbose.
--demo         Generates and analyzes a dummy track, no input file needed.
--help         Prints this help.
```

To actually execute the parser, you could either run a demo
```
./sportgems --demo
```
or use one of the pre-bundled `gpx` files, which is located in the test data directory like
```
./sportgems ../test/data/running.gpx
```
This will print out the information on the fastest sections found in the `gpx`
file, like shown above.


## How does it work?

Sportgems is divided in multiple files. Their purpose is outlined briefly in the following
```
parser.cpp          - used to parse gpx files
generator.cpp       - used to generate dummy activity data for testing
geo.cpp             - used to calculate the distance between coordinates
types.cpp           - specify custom data types
gem_finder.cpp      - core algorithm to search for wanted sections
main.cpp            - entry point for the CLI
exceptions.h        - define custom exceptions
test_helper.h       - custom helper functions for running tests
test_...cpp         - test file for testing the corresponding source files
```

The following diagram illustrates how the core algorithm (implemented in `gem_finder.cpp`) works:

<img src="https://i.imgur.com/Jwfyjsk.png" width="500">


## Running the tests
Sportgems uses [gtest](https://github.com/google/googletest/) for unit testing. However, it is
possible to run all tests (from the build directory) at once, using
```
ctest
```

or you might run individual test suites by executing the compiled binary, e.g.
```
./test_geo
./test_generator
./test_gem_finder
./test_parser
```


## Roadmap

On top of the current implementation, it is further planned to
* parse the sections with highest power (using elevation data)
* deduce [VO2max](https://en.wikipedia.org/wiki/VO2_max) from activity data using the [estimation method of firstbeat](https://assets.firstbeat.com/firstbeat/uploads/2017/06/white_paper_VO2max_30.6.2017.pdf) with heartbeat and speed data
* packaging the sportgems C++ code base into a Python package
* including the sportgems python package into [workoutizer - a sport workout organizer](https://github.com/fgebhart/workoutizer)
