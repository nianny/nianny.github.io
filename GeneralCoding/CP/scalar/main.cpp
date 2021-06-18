#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    for (int i=0; i<n; i++){
        cin>>b[i];
    }

    sort (a, a+n, greater<int>());
    sort (b, b+n);
    
    int ans = 0;
    for (int i=0; i<n; i++){
        ans += a[i]*b[i];
    }
    cout<<ans;
    
    return 0;
}
