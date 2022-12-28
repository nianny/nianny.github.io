#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n,m;
vector<int>adjlist[100010];
bool visited[100010];
void dfs(int x){
    visited[x] = true;
    for (auto i: adjlist[x]){
        if (visited[i]) continue;
        cout<<x<<' '<<i<<'\n';
        dfs(i);
    }
}

void dfs_parent(int x, int p){
    for (auto i: adjlist[x]){
        if (i == p) continue;
        if (visited[i]) continue;
        dfs_parent(i, x);

        cout<<i<<' '<<x<<'\n';
    }

    visited[x] = true;
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;

    cin>>n;
    
    for (int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        // cout<<a<<' '<<b<<'\n';
        // cout<<b<<' '<<a<<'\n';

        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    cin>>m;
    vector<int>points;
    for (int i=0; i<m; i++){
        int h;
        cin>>h;
        cout<<0<<' '<<h<<'\n';
        points.push_back(h);
    }

    // for (int i=1; i<=n; i++){
    //     cout<<i<<'\t';
    //     for (auto x:adjlist[i]){
    //         cout<<x<<' ';
    //     }
    //     cout<<'\n';
    //     if (adjlist[i].size() == 1){
    //         cout<<i<<"HALLO"<<'\n';
    //         dfs_parent(i, -1);
    //     }
    // }
    if (m <= 2){
        for (auto i: points){
            memset(visited, false, sizeof visited);
            dfs(i);
        }
    }
    else{
        for (int i=1; i<=n; i++){
            if (adjlist[i].size() == 1){
                memset(visited, false, sizeof visited);
                dfs(i);
            }
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

