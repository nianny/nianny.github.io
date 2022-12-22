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
        else if (E<=m) return l->query(S,E);
        else if (m < S) return r->query(S,E);
        else return l->query(S,m) + r->query(m+1,E);
    }
} *root = new node(0, 100005);

vector<int> adjlist[100005];
int ss[100005]; //size of subtree
int pre[100005]; //preorder
int post[100005]; //postorder
int pp[100005]; //direct parent
int hp[100005]; //heavy line parent
int depth[100005]; //depth
int COUNTER;
int n,m;

void dfs_ss(int x, int p){
    if (adjlist[x].size() >= 2 && adjlist[x][0] == p) swap(adjlist[x][0], adjlist[x][1]);
    ss[x] = 1;
    for (auto &i: adjlist[x]){
        if (i == p) continue;
        depth[i] = depth[x]+1;
        pp[i] = x;
        dfs_ss(i,x);
        ss[x] += ss[i];
        if (ss[i] > ss[adjlist[x][0]]) swap(i, adjlist[x][0]);
    }
}

void dfs_hld(int x, int p){
    pre[x] = ++COUNTER;

    for (auto i: adjlist[x]){
        if (i==p) continue;

        if (i == adjlist[x][0]) hp[i] = hp[x]; //its a heavy child
        else hp[i] = i; //its the head of its own heavy path

        dfs_hld(i, x);
    }

    post[x] = COUNTER;
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    cin>>n>>m;

    for (int i=1; i<n; i++){
        int a,b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    dfs_ss(1, -1);
    hp[1] = 1;
    dfs_hld(1, -1);

    for (int i=0; i<m; i++){
        char hmm;
        cin>>hmm;
        int a,b;
        cin>>a>>b;

        if (hmm == 'P'){
            while(hp[a] != hp[b]){
                if (depth[hp[a]] < depth[hp[b]]) swap(a,b); //make sure that the heavy chain for a is lower down (kinda like lca where you move each up chain by chain)
                root->update(pre[hp[a]], pre[a], 1);
                a = pp[hp[a]];
            }

            //now they are in the same hld chain
            if (pre[a] > pre[b]) swap(a,b);
            if (a != b) root->update(pre[a]+1, pre[b], 1); //since each node represents the edge above it, we do not update the lca ish thingi
        }
        else{
            int sum = 0;
            while(hp[a] != hp[b]){//while they are not in the same hld chain
                if (depth[hp[a]] < depth[hp[b]]){
                    swap(a,b); //a is in the deeper chain
                }

                sum+=root->query(pre[hp[a]], pre[a]);
                a = pp[hp[a]];
            }

            if (pre[a] > pre[b]) swap(a,b);
            if (a != b) sum += root->query(pre[a]+1, pre[b]);

            cout<<sum<<'\n';
        }
    }


    
    
    return 0;
}
