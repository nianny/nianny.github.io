#!/bin/bash
g++ grader.cpp hunter.cpp -o hunter -Wall -static -O2 -lm -s -w -std=gnu++14 -fmax-errors=512
