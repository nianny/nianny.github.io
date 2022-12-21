#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
struct node{
    int s,e,m;
    int val;
    node *l, *r;

    node(int _s, int _e){
        s = _s, e = _e, m = s+e>>1;
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

            val = min(l->val, r->val);
        }
    }

    int query(int S, int E){
        if (s == S && e == E) return val;
        else{
            if (E <= m) return l->query(S,E);
            else if (m<S) return r->query(S,E);
            else return min(l->query(S,m), r->query(m+1, E));
        }
    }
};

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;

    int n,q;
    cin>>n>>q;

    node *before = new node(0, 200005);
    node *after = new node(0, 200005);
    for (int i=1; i<=n; i++){
        int a;
        cin>>a;
        before ->update(i, a-i);
        after -> update(i, a+i);
    }
    
    for (int i=0; i<q; i++){
        int opt;
        cin>>opt;
        if (opt == 1){
            int k,x;
            cin>>k>>x;

            before ->update(k, x-k);
            after->update(k, x+k);
        }else{
            int k;
            cin>>k;

            cout<<min(before->query(1, k)+k, after->query(k,n)-k)<<'\n';
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

