#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    double t,n,x,k;
    cin>>t>>n>>x>>k;

    for (int i=0; i<n; i++){
        double d,s,w;
        cin>>d>>s>>w;

        t-=w;
        t-= d/s;
    }

    t-=x/k;
    cout<<static_cast<long long>(round(t));
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

