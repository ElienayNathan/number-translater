g++ -c src/*.cpp -I include
move *.o src
g++ src/*.o -o bin/debug/main
start bin/debug/main