#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);

int ans[10];

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int a,b;
    cin>>a>>b;

    for (int i=a; i<=b; i++){
        string halo = to_string(i);
        // cout<<halo<<'\n';
        for (auto i: halo){
            ans[i-'0']++;
        }
    }

    for (int i=0; i<10; i++){
        cout<<ans[i]<<'\n';
    }
    
    return 0;
}