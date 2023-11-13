#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int p[300005];
bool has_airport[300005];
int find(int x){
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b){
    p[find(a)] = find(b);
}

bool same_set(int a, int b){
    return find(a) == find(b);
}


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;

    int n,r;
    cin>>n>>r;

    for (int i=0; i<=n; i++){
        p[i] = i;
    }
    vector<pair<int,pair<int,int>>> v;
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back({x, {i, n}});
    }

    
    for (int i=0; i<r; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({c, {a,b}});
    }

    sort(v.begin(), v.end());
    int cost = 0;
    for (auto it: v){
        if (!same_set(it.second.first, it.second.second)){
            merge(it.second.first, it.second.second);
            cost += it.first;
        }
    }

    cout<<cost;
    /*
    Hallooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    */
    return 0;
}

