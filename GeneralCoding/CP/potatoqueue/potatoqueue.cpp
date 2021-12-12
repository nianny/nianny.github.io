#include "potatoqueue.h"
#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
int idx;

void init(){
	idx = 1;
}
void join(int H){
	q.push(make_pair(H, idx));
	idx++;
}
void serve(){
}
int query(int N){
	return N;
}
