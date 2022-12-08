#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int p[1000010];

int find_set(int x){
    if (p[x] == x) return x;
    p[x] = find_set(p[x]);
    return p[x];
}

void merge_set(int a, int b){
    p[find_set(a)] = find_set(b);
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,e;
    cin>>n>>e;
    for (int i=1; i<=n; i++){
        p[i] = i;
    }
    vector<pair<int,pair<int,int>>> edgelist;
    for (int i=0; i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;
        edgelist.push_back({c, {a,b}});
    }

    sort(edgelist.begin(), edgelist.end());

    int pos = 0;
    int longest = 0;
    while (pos < edgelist.size() && find_set(1) != find_set(n)){
        // cout<<pos<<' '<<edgelist[pos].first<<'\n';
        longest = max(longest, edgelist[pos].first);
        merge_set(edgelist[pos].second.first, edgelist[pos].second.second); // considering this road
        pos++;
    }

    cout<<longest;
    
    return 0;
}
