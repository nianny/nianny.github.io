#include <bits/stdc++.h>
#include "hunter.h"
using namespace std;


vector<int>adjlist[10000];
int pre[10000];
int counter = 0;
void dfs(int x, int p){
    pre[x] = counter;
    counter++;
    for (auto i: adjlist[x]){
        if (i == p) continue;
        dfs(i, x);
    }
}
void hunter(int N, int M, int S, int D, std::vector<int> A, std::vector<int> B){
// 	int x = search_towns(0,1);
	
// }

// void hunter(int N, int M, int S, int D, std::vector<int> A, std::vector<int> B){
//     // int x = search_towns(0,1);
    
    for (int i=0; i<M+2*N-1; i++){
        adjlist[B[i]].push_back(A[i]);
        adjlist[A[i]].push_back(B[i]);
    }

    dfs(0, -1);
    vector<pair<int,int>> a;
    vector<pair<int,int>> b;

    for (int i=M; i<M+N; i++){
        a.push_back({pre[i], i});
    }

    for (int i=M+N; i<M+2*N; i++){
        b.push_back({pre[i], i});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i=0; i<N; i++){
        search_towns(a[i].second, b[i].second);
    }



}

// int32_t main() {
//     // ifstream cin("addin.txt");
//     // ofstream cout("addout.txt");
//     hallo;
    
//     /*
//     雪花飘飘北风萧萧
//     天地一片苍茫
//     一剪寒梅傲立雪中
//     只为伊人飘香
//     */
//     return 0;
// }

