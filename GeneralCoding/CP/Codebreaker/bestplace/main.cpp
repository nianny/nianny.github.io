#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    int arx[n];
    int ary[n];
    for (int i=0; i<n; i++){
        cin>>arx[i]>>ary[i];
    }

    sort(arx, arx+n);
    sort(ary, ary+n);

    cout<<arx[n/2]<<' '<<ary[n/2];
    
    return 0;
}
