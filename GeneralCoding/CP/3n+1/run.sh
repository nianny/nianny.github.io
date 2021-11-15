g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o gen.exe gen.cpp
g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o main.exe main.cpp
g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o brute.exe brute.cpp

for((i = 1; ; ++i)); do
    echo $i
    ./gen.exe $i > int
    diff -w <(./main.exe < int) <(./brute.exe < int) || break
done