#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,x;
    cin>>n>>x;
    int D[n];
    int W[n];
    for (int i=0; i<n; i++){
        cin>>D[i];
    }

    for (int i=0; i<n; i++){
        cin>>W[i];
    }
    int ss[n];
    ss[0] = D[0];
    for (int i=1; i<n; i++){
        ss[i] = ss[i-1]+D[i];
    }

    int l=0;
    int r=0;

    int sum = 0;
    deque<int>dq;

    while(r <= n){
        
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

