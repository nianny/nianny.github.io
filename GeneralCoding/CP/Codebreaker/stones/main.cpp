#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<int> adjlist[1000010];
int ss[1000010];
int stones[1000010];

void dfs(int x, int p){
    ss[x] = 1;
    for (auto i: adjlist[x]){
        if (i == p) continue;
        dfs(i, x);
        ss[x] += ss[i];
        stones[x] += stones[i];
    }
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    int root;

    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        if (a != -1) adjlist[a].push_back(i);
        else root = i;
        stones[i] = b;
    }

    dfs(root, -1);

    int ans = 0;

    for (int i=0; i<n; i++){
        ans += abs(stones[i] - ss[i]);
    }

    cout<<ans;


    return 0;
}

