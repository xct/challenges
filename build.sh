rm -r build32
rm -r build64
mkdir build32
mkdir build64

# 32-Bit
gcc -m32 -o ./build32/000 ./src/000.c
gcc -m32 -o ./build32/001 ./src/001.c
gcc -m32 -o ./build32/002 ./src/002.c
gcc -m32 -o ./build32/003 ./src/003.c
gcc -m32 -o ./build32/004 ./src/004.c

# 64-Bit
gcc -o ./build64/000 ./src/000.c
gcc -o ./build64/001 ./src/001.c
gcc -o ./build64/002 ./src/002.c
gcc -o ./build64/003 ./src/003.c
gcc -o ./build64/004 ./src/004.c

echo "Done"