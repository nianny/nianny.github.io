#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int pre[100010];
int post[100010];


struct node{
    int s,e,m;
    int val;
    set<int> setto;
    node *l, *r;

    node(int _s, int _e){
        s=_s, e=_e, m=s+e>>1;
        val = 0;

        if (s != e){
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }

    void propo(){

    }
};

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

