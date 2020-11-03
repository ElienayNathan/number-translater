g++ -c src/*.cpp -I include
move *.o src
g++ src/*.o -o main