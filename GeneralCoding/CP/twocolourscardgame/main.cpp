#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    map <string, int> hi;
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        string a;
        cin>>a;
        hi[a] += 1;
    }
    int m;
    cin>>m;
    for (int i=0; i<m; i++){
        string a;
        cin>>a;
        hi[a] -= 1;
    }
    int ans = 0;
    for (auto it: hi){
        ans = max(ans, it.second);
    }
    cout<<ans;
    return 0;
}