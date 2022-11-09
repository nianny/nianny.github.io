#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


struct node{
    int s, e, m;
    int val;
    node *l, *r;
    node (int S, int E){
       s = S, e = E, m = (s+e)/2;
       val = 0;
    }
    void propogate(){
        if(s != e){ 
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }
    void update(int X, int V){
        if(s == e) val = V;
        else{
            if(l == nullptr) propogate();
            if(X <= m) l->update(X, V);
            else r->update(X, V);
            val = l->val + r->val;
        }
    }

    int query(int S, int E){
        if(l == nullptr) propogate(); 
        if(s == S && e == E) return val;
        else if(E <= m) return l->query(S, E);
        else if(S >= m+1) return r->query(S, E);
        else return l->query(S, m) + r->query(m+1, E);
    }
    
} *root = new node(1, 1000000000);

int32_t main() {
    return 0;
}