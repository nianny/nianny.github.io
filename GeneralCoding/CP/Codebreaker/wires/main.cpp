#include <bits/stdc++.h>
#include "wires.h"
using namespace std;
// #define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


// int32_t main() {
//     // ifstream cin("addin.txt");
//     // ofstream cout("addout.txt");
//     hallo;
    
//     /*
//     雪花飘飘北风萧萧
//     天地一片苍茫
//     */
//     return 0;
// }

// void wires

void wire(int N, int P, int order[]){

    int vert = 1;
    int hori = 1;
    vector<int> solution;
    // cout<<N<<' '<<vert<<' '<<hori<<'\n';

    while(vert <= N && hori <= N){
        // cout<<vert<<' '<<hori<<' '<<press(vert,hori)<<'\n';
        if (press(vert, hori)){
            vert++;
            solution.push_back(0);
            
        }
        else{
            hori++;
            solution.push_back(1);
        }
    }

    for (int i=vert; i<=N; i++){
        solution.push_back(0);
    }
    for (int i=hori; i<=N; i++){
        solution.push_back(1);
    }
	for (int i=0; i<2*N; i++){
        order[i] = solution[i];
        // cout<<solution[i]<<' ';
    }
}