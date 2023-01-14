#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n,q;
vector<pair<int,int>>adjlist[100010];
int twok[100010][20];
int ss[100010];
int depth[100010];

void dfs(int x, int p){
    twok[x][0] = p;
    for (auto i: adjlist[x]){
        if (i.first == p) continue;
        ss[i.first] = ss[x] + i.second;
        depth[i.first] = depth[x] + 1;
        // twok[i.first][0] = x;
        dfs(i.first, x);
    }
}

int kpar(int x, int k){
    for (int i=0; i<20; i++){
        if (k & (1<<i)) x = twok[x][i];
    }

    return x;
}

int lca(int a, int b){
    if (depth[a] < depth[b]) swap(a,b);
    a = kpar(a, depth[a]-depth[b]);

    if (a == b) return a;
    for (int k=19; k>=0; k--){
        if(twok[a][k] != twok[b][k]){
            a = twok[a][k]; b = twok[b][k];
        }
    }

    return twok[a][0];
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    cin>>n>>q;

    for (int i=0; i<n-1; i++){
        int a,b,c;
        cin>>a>>b>>c;

        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }
    ss[1] = 0;
    depth[1] = 0;
    dfs(1, -1);

    for (int k=1; k<20; k++){
        for (int i=1; i<=n; i++){
            if (twok[i][k-1] != -1) twok[i][k] = twok[twok[i][k-1]][k-1];
            else twok[i][k] = -1;
        }
    }

    for (int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;

        cout<<ss[a]+ss[b]-2*ss[lca(a,b)]<<'\n';
    }

    // for (int i=1; i<=n; i++){
    //     cout<<ss[i]<<' ';
    // }

    
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

