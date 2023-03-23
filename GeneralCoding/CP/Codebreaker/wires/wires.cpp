#include "wires.h"
#include <bits/stdc++.h>

void wire(int N, int P, int order[]){
	int ok = press(1,1);
	for (int i = 0; i < N; ++i){
		order[i] = 0;
	}
	for (int i = N; i < 2*N; ++i){
		order[i] = 1;
	}
}