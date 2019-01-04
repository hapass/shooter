# Shooter

## Setup and run

1. Install [brew](https://brew.sh)
1. Install [xcode](https://developer.apple.com/xcode/)
1. Download and unpack [murl](https://murlengine.com/?murlpage=download&murllang=en&murlfile=murl_2018.2.7478.zip)
1. Install clang-format. Terminal: *brew install clang-format*
1. Install cmake. Terminal: *brew install cmake*
1. Copy and rename template CMakeProperties.txt.in to CMakeProperties.txt
1. Configure your path to murl folder of the murl engine in CMakeProperties.txt
1. Build. Terminal: *./build.sh Release*
1. Run. Terminal: *open build/Release/shooter.app*