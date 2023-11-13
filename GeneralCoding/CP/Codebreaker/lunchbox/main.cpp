#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,m;
    cin>>n>>m;

    vector<int>v(m);
    for (int i=0; i<m; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    int ans = 0;
    while (ans < m && n>=v[ans]){
        n-=v[ans];
        ans++;
    }
    cout<<ans;
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

