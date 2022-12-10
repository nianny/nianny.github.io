#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

struct node{
    int s,e,m;
    int prefix, suffix, sum, maxrange, val;
    node *l = nullptr, *r = nullptr;


    node (int S, int E){
        s = S; e = E; m = (s+e)/2;
        // val = 0;
        prefix = 0;
        suffix = 0;
        sum = 0;
        maxrange = 0;
    }

    void create(){
        if (s != e){
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }

    void update(int X, int V){
        if (l==nullptr) create();

        if (s == e){
            sum = V;
            prefix = max((int)0, sum);
            suffix = max((int)0, sum);
            maxrange = max((int)0, sum);
        }

        else{
            if (X <= m) l->update(X,V);
            else r->update(X,V);

            sum = l->sum + r->sum;
            prefix = max(l->prefix, l->sum + r->prefix);
            suffix = max(r->suffix, r->sum + l->suffix);

            maxrange = max(max(l->maxrange, r->maxrange), l->suffix + r->prefix);
        }
    }

    int query(){
        return maxrange;
    }
} *root = new node(0, 1000010);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;

    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        root->update(i,a);
    }
    cout<<root->query()<<'\n';

    //cout<<root->sum<<' '<<root->maxrange<<' '<<root->prefix<<' '<<root->suffix<<'\n';
    // cout<<root->l->sum<<' '<<root->l->maxrange<<' '<<root->l->prefix<<' '<<root->l->suffix<<'\n';
    int m;
    cin>>m;
    
    for (int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        root->update(a,b);
        cout<<root->query()<<'\n';
        //cout<<root-> sum<<' '<<root->maxrange<<' '<<root->prefix<<' '<<root->suffix<<'\n';
    }
    
    return 0;
}
