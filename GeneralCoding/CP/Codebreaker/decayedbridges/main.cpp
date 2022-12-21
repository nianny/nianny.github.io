#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int p[100010];
int ss[100010];

int find_set(int x){
    if (p[x] == x) return x;
    p[x] = find_set(p[x]);

    return p[x];
}

void merge_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    p[a] = b;
    ss[b] += ss[a];
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>v;
    for (int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    reverse(v.begin(), v.end());
    

    int inconvenience = n*(n-1)/2;
    vector<int> ans;
    
    for (int i=0; i<=n; i++){
        p[i] = i;
        ss[i] = 1;
    }

    for (int i=0; i<m; i++){
        ans.push_back(inconvenience);
        if (find_set(v[i].first) != find_set(v[i].second)){
            inconvenience -= (ss[find_set(v[i].first)] * ss[find_set(v[i].second)]);
        
            merge_set(v[i].first, v[i].second);
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto i: ans){
        cout<<i<<'\n';
    }
    
    return 0;
}
