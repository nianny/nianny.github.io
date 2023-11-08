#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,a,b;
    cin>>n>>a>>b;

    vector<pair<int,int>>v;
    for (int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({abs(x-a)+abs(y-b),i});
    }

    sort(v.begin(),v.end());
    for (int i=0; i<n; i++){
        cout<<v[i].second<<endl;
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

