g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o gen.exe gen.cpp
g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o main.exe main.cpp
g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o brute.exe brute.cpp

for((i=1; i<= 100; i++)); do
    echo $1
    ./gen.exe $1 > in
    diff -w <(./main.exe < in) <(./brute.exe < in) || break
done