#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


//lazy prop range sum
struct node{
    int s,e,m;
    int val;
    node *l, *r;
    int lazy;

    node(int S, int E){
        s =S, e=E, m=s+e>>1;
        val = 0;
        lazy = 0;
        if (s != e){
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }

    void propo(){
        if (lazy == 0) return;
        val += lazy*(e-s+1);

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
            else l->update(S, m, V), r->update(m+1, E, V);

            l->propo(), r->propo();
            val = l->val + r->val;
        }
    }

    int query(int S, int E){
        propo();
        if (s == S && e == E) return val;
        else{
            if (m >= E) return l->query(S,E);
            else if (m < S) return r->query(S,E);
            else return l->query(S,m) + r->query(m+1, E);
        }
    }
}*root = new node(0, 500010);
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,q;
    cin>>n>>q;

    for (int i=0; i<q; i++){
        int op;
        cin>>op;
        if (op == 1){
            int l,r,x;
            cin>>l>>r>>x;
            root->update(l,r,x);
        }
        else if (op == 4){
            int l,r;
            cin>>l>>r;
            cout<<root->query(l,r)<<'\n';
        }
        else{
            return 69;
        }
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    一剪寒梅傲立雪中
    只为伊人飘香
    */
    return 0;
}

