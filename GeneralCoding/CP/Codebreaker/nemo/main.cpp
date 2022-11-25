#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int parent[50010];
    
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,e;
    cin>>n>>e;

    for (int i=0; i<n; i++){
        parent[i] = i;
    }

    vector<pair<int, pair<int,int>>> open;
    vector<pair<int, pair<int,int>>> close;

    for (int i=0; i<e; i++){
        int a,b,o,c;
        cin>>a>>b>>o>>c;
        open.push_back({o, {a,b}});
        close.push_back({c, {a,b}});
    }

    int tc;
    cin>>tc;
    vector<pair<int, pair<int,pair<int,int>>>> query;
    for (int i=0; i<tc; i++){
        int x,y,t;
        cin>>x>>y>>t;
        query.push_back({t, {i, {x,y}}});
    }

    sort(open.begin(), open.end());
    sort(close.begin(), close.end(), greater<pair<int,pair<int,int>>>());
    sort(query.begin(), query.end());
    
    return 0;
}
