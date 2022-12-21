#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

//range add sum query seg tree
struct node{
    int s,e,m;
    int val=0, lazy =0;
    node *l, *r;

    node(int _s, int _e){
        s = _s, e=_e, m = s+e>>1;
        
        if (s != e){
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }

    void propo(){
        if (lazy == 0) return;

        val += lazy * (e-s+1);
        if (s != e){
            l->lazy += lazy;
            r->lazy += lazy;
        }

        lazy = 0;
    }

    void update(int S, int E, int V){
        if (s == S && e == E) lazy += V;
        else{
            if (m >= E) l->update(S,E,V);
            else if (m<S) r->update(S,E,V);
            else l->update(S,m,V), r->update(m+1, E, V);

            l->propo(), r->propo();

            val = l->val + r->val;
        }
    }

    int query(int S, int E){
        propo();
        if (s == S && e == E) return val;
        else if (E<=m) l->query(S,E);
        else if (m < S) r->query(S,E);
        else return l->query(S,m) + r->query(m+1,E);
    }
} *root = new node(0, 100005);

int size[100005]; //size of subtree
int pre[100005]; //preorder
int post[100005]; //postorder
int pp[100005]; //direct parent
int hp[100005]; //heavy line parent
int depth[100005]; //depth

int dfs_ss(int x, int p){
    if (adjl)
}
 

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    
    
    return 0;
}
