#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n;
int MOD;
int multiples[200005];
struct node{
    int s,e,m;
    // int lazy;
    int val;
    node *l, *r;

    node(int S, int E){
        s=S, e=E, m=s+e>>1;
        // lazy = 0;
        val = 0;

        if (s != e){
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }

    void update(int X, int V){
        if (s == e) val = V;
        else{
            if (X <= m) l->update(X,V);
            else r->update(X,V);

            val = ((l->val * multiples[e-m])%MOD + r->val)%MOD;
        }
    }

    int query(int S, int E){
        if (s == S && e == E) return val;
        else{
            if (E <= m) return l->query(S,E);
            else if (m < S) return r->query(S,E);
            else{
                return ((l->query(S,m)*multiples[E-m])%MOD + r->query(m+1, E))%MOD;
            }
        }
    }
} *root;


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    cin>>n>>MOD;
    multiples[0] = 1;
    for (int i=1; i<=n; i++){
        multiples[i] = (multiples[i-1]*10)%MOD;
    }

    root = new node(0, n);

    for (int i=1; i<=n; i++){
        char a;
        cin>>a;

        root->update(i, (int)(a-'0'));
    }

    // for (int i=0; i<=n; i++){
    //     cout<<root->query(i,i)<<' ';
    // }
    // cout<<'\n';
    int q;
    cin>>q;

    for (int i=0; i<q; i++){
        int pol;
        cin>>pol;
        if (pol == 1){
            int l,r;
            cin>>l>>r;
            cout<<root->query(l,r)<<'\n';
        }
        else{
            int x,v;
            cin>>x>>v;
            root->update(x, v);
        }
    }
    // cout<<1%0;
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

