g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o gen.exe gen.cpp
g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o main.exe main.cpp
g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o brute.exe brute.cpp

i=1
while [ "$i" -le 100 ]; do
    echo "$i"
    ./gen.exe > int
    diff -w <(./main.exe < int) <(./brute.exe < int) || break
    i=$(( i + 1 ))
done