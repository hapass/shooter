engine_path="lib/murl"
engine_url="https://download.murlengine.com/murl_2019.2.7714.zip"

mkdir -p $engine_path
cd $engine_path

curl $engine_url --output murl.zip
unzip murl.zip
rm murl.zip

cd $OLDPWD

rm -f CMakeProperties.txt
echo "set(murl_PATH \"$PWD/$engine_path/murl\" CACHE STRING \"path to murl engine\")" > CMakeProperties.txt

brew list clang-format &>/dev/null || brew install clang-format
brew list cmake &>/dev/null || brew install cmake

./build.sh Release
open build/Release/shooter.app