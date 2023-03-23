#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

struct node{
    int s,e,m;
    int val, lazy;
    node *l=nullptr, *r=nullptr;
    node(int S, int E){
        s = S; e=E; m=s+e>>1;
        val = 0;
        lazy = 0;
    }

    void propo(){
        if (lazy == 0) return;

        val = (e-s+1);
        if (l==nullptr) create();
        if (s != e){
            l->lazy = 1;
            r->lazy = 1;
        }
        lazy = 0;
    }

    void create(){
        if (s != e){
            l = new node(s,m);
            r = new node(m+1, e);
        }
    }

    void update(int S, int E){
        if (lazy == 1) return;
        if (l == nullptr) create();
        if (s == S && e == E) lazy = 1;
        else{
            if (E <= m) l->update(S,E);
            else if (m < S) r->update(S,E);
            else l->update(S,m), r->update(m+1, E);
            l->propo(); r->propo();

            val = l->val + r->val;
        }
    }

    int get(int S, int E){
        if (l == nullptr) create();
        propo();

        if (s == S && e == E) return val;
        else if (E <= m) return l->get(S,E);
        else if (m < S) return r->get(S,E);
        else return l->get(S,m) + r->get(m+1,E);
    }
    int query(){
        return val;
    }
}*root = new node(1, 1000000010);
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int l,r;
    cin>>l>>r;
    for (int i=0; i<r; i++){
        int x;
        cin>>x;

        // vector<int> v;
        // for (int j=0; j<x; j++){
        //     int a;
        //     cin>>a;
        //     v.push_back(a);
        // }

        vector<int>ss;
        ss.push_back(0);

        for (int j=0; j<x; j++){
            int a;
            cin>>a;
            ss.push_back(a+ss.back());
        }

        for (int j=1; j<=x; j++){
            int front = ss[j];
            int back = l - (ss[x]-ss[j-1])+1;

            if (back <= front){
                root->update(back, front);
            }
        }
    }
    cout<<root->query();

    // cout<<'\n';
    // for (int i=1; i<=l; i++){
    //     cout<<root->get(i,i)<<' ';
    // }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

