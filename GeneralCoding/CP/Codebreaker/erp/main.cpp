#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,e;
    cin>>n>>e;
    vector<pair<int,int> > adjlist[n]
    for (int i=0; i<e; i++){
        int a,b,f;
        cin>>a>>b>>f;
        adjlist[a].push_back(make_pair(b,f));
        adjlist[b].push_back(make_pair(a,f));
    }

    int dist1[n];
    int dist2[n];
    memset()
    return 0;
}
