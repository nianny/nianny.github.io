#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>adjlist[100010];
int depth[100010];
int pp[100010]; //immediate parent
int hp[100010]; //parent of hld chain
int pre[100010]; //preorder
int ss[100010]; //size

struct node{
    int s,e,m;
    int val;
    int lazy;
    node *l, *r;

    node(int _s, int _e){
        s = _s, e=_e, m = s+e>>1;
        val = 0;
        lazy = 0;
        if (s != e){
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }

    void propo(){
        if (lazy == 0) return;

        val += lazy * (e-s+1);
        if (s != e){
            l -> lazy += lazy;
            r -> lazy += lazy;
        }
        lazy = 0;
    }
    //update
    void update(int _s, int _e, int v){
        if (s == _s && e == _e) lazy += v;
        else{
            if (_e <= m) l->update(_s, _e, v);
            else if (m<_s) r->update(_s, _e, v);
            else l->update(_s, m, v), r->update(m+1, _e, v);
            l->propo(), r->propo();

            val = l->val + r->val;
        }
    }

    //query
    int query(int _s, int _e){
        propo();
        if (s == _s && e == _e) return val;
        else{
            if (_e <= m) return l->query(_s, _e);
            else if (m<_s) return r->query(_s, _e);
            else return l->query(_s, m)+r->query(m+1, _e);
        }
    }
}*root = new node(0, 100010);


void dfs_ss(int i, int p){
    if (adjlist[i].size() >= 2 && adjlist[i][0] == p) swap(adjlist[i][0], adjlist[i][1]);
    ss[i] = 1;
    for (auto &it: adjlist[i]){
        if (it == p) continue;
        depth[it] = depth[i]+1;
        pp[it] = i;
        dfs_ss(it, i);
        ss[i] += ss[it];

        if (ss[it] > ss[adjlist[i][0]]) swap(it, adjlist[i][0]);
    }
}

int COUNTER;
void dfs_hld(int i, int p){
    pre[i] = ++COUNTER;
    for (auto it: adjlist[i]){
        if (it == p) continue;
        
        
        if (it == adjlist[i][0]) hp[it] = hp[i];
        else hp[it] = it;
        dfs_hld(it, i);
    }
}

int n,m;
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
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
        char choice;
        int a,b;
        cin>>choice>>a>>b;

        if (choice == 'P'){
            while(hp[a] != hp[b]){
                if (depth[hp[a]] < depth[hp[b]]){
                    swap(a,b);
                }
                root->update(pre[hp[a]], pre[a], 1);
                a = pp[hp[a]];
            }

            //same chain
            if (pre[a] > pre[b]) swap(a,b);
            if (a != b) root->update(pre[a]+1, pre[b], 1);
        }
        else{
            int sum = 0;
            while(hp[a] != hp[b]){
                if (depth[hp[a]] < depth[hp[b]]){
                    swap(a,b);
                }
                sum += root->query(pre[hp[a]], pre[a]);
                a = pp[hp[a]];
            }

            if (pre[a] > pre[b]) swap(a,b);
            if (a != b) sum += root->query(pre[a]+1, pre[b]);
            cout<<sum<<'\n';
        }
    }
    return 0;
}