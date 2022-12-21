#include <bits/stdc++.h>
#include "hunter.h"

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int x, int y){
	if (x == y) return x;
	return x + (rng()%(y-x+1));
}	

const string ERROR0 = "Something went wrong :(";
const string ERROR1 = "Wrong Answer: Invalid query made";
const string ERROR2 = "Wrong Answer: Too many queries made";
const string ERROR3 = "Wrong Answer: Thug leader not found";

static int N, M, subtask, D, X, Y, visited[4005], location;
static vector<int> AdjList[4005], A, B, S;
static int query_count = 0, solved = 0;
static int found;

void quit(string str){
    printf("%s\n",str.c_str());
}

void printAC(){
	printf("Accepted\n");
	printf("Queries Used: %d\n",query_count);
	exit(0);
}

void find_cities(int v, int goal){
	if (v == goal){
		found = 1;
		S.push_back(v);
		return;
	}
	visited[v] = 1;
	for (int i = 0; i < AdjList[v].size(); ++i){
		if (!visited[AdjList[v][i]]){
			find_cities(AdjList[v][i],goal);
			if (found){
				S.push_back(v);
				return;
			}
		}
	}
}


int search_towns(int X, int Y){
	if (X < 0 || X > 2*N+M-1 || Y < 0 || Y > 2*N+M-1 || X == Y) quit(ERROR1);
	query_count++;
	if (!solved && query_count > D) quit(ERROR2);
	S.clear();
	for (int i = 0; i < 2*N+M; ++i) visited[i] = 0;
	found = 0;
	find_cities(X,Y);
	if (!found) quit(ERROR0);
	for (auto it : S){
		if (it == location){
			solved = 1;
			printAC();
			return 1;	
		}
	}
	S.clear();
	return 0;
}


int readint(){
    int x;
    if(scanf("%d",&x)!=1) quit(ERROR0);
    return x;
}

int main(){
	N = readint();
	M = readint();
	subtask = readint();
	D = readint();
	for (int i = 0; i < 2*N+M-1; ++i){
		X = readint();
		Y = readint();
		AdjList[X].push_back(Y);
		AdjList[Y].push_back(X);
		A.push_back(X);
		B.push_back(Y);
	}
	location = rand(0,2*N+M-1);
	hunter(N,M,subtask,D,A,B);
	if (!solved) quit(ERROR3);
}
