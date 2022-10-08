sudo apt install pkg-config uuid-dev cmake git
git clone https://github.com/antlr/antlr4.git --branch 4.7.2 --single-branch antlr-runtime --depth 1
cd antlr-runtime/runtime/Cpp
mkdir build run
cd build
cmake ..
DESTDIR=../run make install -j 8
cd ../run/usr/local/include
sudo cp -r antlr4-runtime /usr/local/include
cd ../lib
sudo cp * /usr/local/lib
sudo ldconfig
cd ../../../../../../..
rm -rf ./antlr-runtime