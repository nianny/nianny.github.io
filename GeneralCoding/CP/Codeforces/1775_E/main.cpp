#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int t;
    cin>>t;

    for (int i=0; i<t; i++){
        int n;
        cin>>n;

        int ss[n+5];
        ss[0] = 0;
        for (int x=1; x<=n; x++){
            int a;
            cin>>a;
            ss[x] = ss[x-1] + a;
        }

        cout<<*max_element(ss, ss+n+1)-*min_element(ss, ss+n+1)<<'\n';
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

