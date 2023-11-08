#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,d;
    cin>>n>>d;

    vector<int>v;
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for (int i=0; i<d; i++){
        ans += v[i];
    }
    cout<<ans<<endl;
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

