#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n,e,k;
// vector<pair<int, pair<int,int>>> edgelist;
// int p[200010];

// int find_set(int x){
//     if (p[x] == x) return x;
//     p[x] = find_set(p[x]);
//     return p[x];
// }

// void merge_set(int a, int b){
//     p[find_set(a)] = find_set(b);
// }

// bool same_set(int a, int b){
//     return find_set(a) == find_set(b);
// }
vector<pair<int,int>>adjlist[200010];
bool possible(int x){
    // for (int i=1; i<=n; i++){
    //     p[i] = i;
    // }
    
    // for (auto i: edgelist){
    //     if (i.first > x){
    //         break;
    //     }

    //     merge_set(i.second.first, i.second.second);
    // }

    // cout<<x<<'\t';
    // for (int i=1; i<=n; i++){
    //     cout<<p[i]<<' ';
    // }
    // cout<<'\n';

    // if (same_set(1, n)){
    //     return true;
    // }else{
    //     return false;
    // }

    queue<int>q;
    int dist[n+5];
    memset(dist, -1, sizeof dist);
    dist[1] = 0;
    q.push(1);

    while (!q.empty()){
        auto c = q.front(); q.pop();
        if (dist[c] == k) continue;
        for (auto i: adjlist[c]){
            if (i.second > x) continue;
            if (dist[i.first] != -1) continue;
            dist[i.first] = dist[c] + 1;
            q.push(i.first);
        }
    }

    if (dist[n] == -1) return false;
    else return true;



}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    
    cin>>n>>e>>k;

    // vector<pair<int,int>> adjlist[n+5];
    

    for (int i=0; i<e; i++){
        int a,b,w;
        cin>>a>>b>>w;

        adjlist[a].push_back({b,w});
        adjlist[b].push_back({a,w});
        // edgelist.push_back({w, {a,b}});
    }

    // sort (edgelist.begin(), edgelist.end());

    int l=-1, r=1e10;
    while (r-l > 1){
        int middle = (r+l)/2;
        if (possible(middle)){
            r=middle;
        }
        else{
            l=middle;
        }
    }

    if (r==1e10) cout<< -1;
    else cout<<r<<'\n';
    
    return 0;
}
