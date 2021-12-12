#!/bin/bash

NAME=potatoqueue

/usr/bin/g++ -DEVAL -Wall -static -O2 -o $NAME grader.cpp potatoqueue.cpp
