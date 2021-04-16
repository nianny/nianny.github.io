#include <bits/stdc++.h>
using namespace std;
#define int long long

int flip(int a){
    if (a == 1) return -1;
    else if (a == -1) return 1;
    return 0;
}

struct node { //create segment tree
    int s, e, m, val;
    bool lazy;
    node *l, *r;
    node(int _s, int _e){
        s = _s; e = _e; m = (s+e)/2;
        lazy = false;
        val = 1; //standing up -> 1
        if (s!=e){
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }

    void propogate() {
        
    }

    void upd(int x, int y){
        if (x<=s && y>=e){
            lazy = !lazy;
            val = flip(val);
            return;
        }
        
        if (x>m){
            r->upd(x,y);
        }
    }
    

    int qry() {
        propogate();
        if (s == e) return s;

        if (r->val != -1) return r->qry();
        else return l->qry();
    }
} *root;
int32_t main() {
    
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n, m, b, k;
    cin>>n>>m>>b>>k;
    bool choice[k];
    for (int i=0; i<k; i++){
        char a;
        cin>>a;
        if (a == 'B'){
            choice[i] = true;
        }
        else {
            choice[i] = false;
        }
    }
    // root = new node();
    
    return 0;
}