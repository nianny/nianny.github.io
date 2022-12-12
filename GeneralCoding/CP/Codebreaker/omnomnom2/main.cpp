#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n;
// int child[500010];
vector<int>adjlist[500010];
int s[500010];
int par[500010];
vector<int>better[500010];

void dfs(int x){
    int tot = 1;
    for(auto i: better[x]){
        dfs(i);
        tot += s[i];
    }

    s[x] = tot;
    return;
}

void root(int x, int p){
    par[x] = p;
    for (auto i: adjlist[x]){
        if (i == p)continue;
        root(i,x);
    }
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    cin>>n;
    for (int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        // par[b] = a;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    // par[1] = 1;
    root(1, 0);

    for (int i=2; i<=n; i++){
        //cout<<i<<' '<<par[i]<<'\n';
        better[par[i]].push_back(i);
    }


    dfs(1);
    int sum = 0;
    for (int i=1; i<=n; i++){
        for (auto p: better[i]){
            sum+= 2*s[p]* (s[1]-s[p]);
        }
    }
    cout<<sum;


    
    
    return 0;
}
