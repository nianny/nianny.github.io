#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
struct node{
    int s,e,m;

    int val[4]; //start+end, start+no end, no start+no end, no start+end

    node(int _s, int _e){
        s=_s,e=_e,m=s+e>>1;
        for (int i=0; i<4; i++){
            val[i] = 0;
        }
    }

    void update(int x, int v){
        if (s == e){
            val[0] = v;
            
        }
    }
}*root = new node(0, 40010);

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;

    int n,d;
    cin>>n>>d;

    for (int i=1; i<=n; i++){

    }
    
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

