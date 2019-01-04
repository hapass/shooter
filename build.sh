mkdir -p build
cd build

cmake -C ../CMakeProperties.txt -GXcode ..
xcodebuild -project shooter.xcodeproj -target shooter -configuration $1