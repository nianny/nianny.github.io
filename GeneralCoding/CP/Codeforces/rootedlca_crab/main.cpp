#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int p[500005][20];
vector<int> adjlist[500005];
int depth[500005];
int kth_parent(int x, int k){
    for (int i = 0; i <= 20; i++){
        if (k & (1 << i)) x = p[x][i];
        if (x <= -1) return -1;
    }
    return x;
}
void roottree(int x, int par) { // x=current node, p=parent 
    p[x][0] = par; // store parent
    for (int i : adjlist[x]) {
        if (i == par) continue;
        depth[i] = depth[x] + 1;
        roottree(i, x); // only continue dfs for children
    }
}

int lca (int a, int b){
    if (depth[a] < depth[b]) swap(a,b);
    a = kth_parent(a, depth[a]-depth[b]);

    if (a == b) return a;
    for (int k=19; k>=0; k--){
        if (p[a][k] != p[b][k]){
            a = p[a][k]; b = p[b][k];
        }
    }

    return p[a][0];
}




int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,q;
    cin>>n>>q;
    memset(depth, -1, sizeof depth);

    for (int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    depth[1] = 0;
    roottree(1, -1);

    for (int k=1;k<20;k++) {
        for (int i=1;i<=n;i++) {
            if (p[i][k-1] != -1) {
                p[i][k] = p[p[i][k-1]][k-1]; // 2^k parent is the 2^(k-1)th parent’s 2^(k-1)th parent
            } else p[i][k] = -1; // no 2^k-th parent
        }
    }

    
    for (int i=0; i<q; i++){
        int r,x,y;
        cin>>r>>x>>y;
        cout<<lca(x,y)<<'\n';
        
    }
    
    // for (int i=0; i<n; i++){
    //     cout<<p[i][0]<<' ';
    // }
    // cout<<'\n';
    
    
    return 0;
}
