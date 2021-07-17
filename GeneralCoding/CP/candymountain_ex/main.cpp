#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi;
    int n, k;
    cin>>n>>k;
    int arr[n+2];
    memset(arr, 0, sizeof(arr));
    for (int i=1; i<=n; i++){
        cin>>arr[i];
    }

    int dp[n+5];
    multiset<int> s;
    memset(dp, 0, sizeof(dp));
    s.insert(0);

    for (int i=1; i<=n+1; i++){
        
        dp[i] = max(*s.begin(), arr[i]);
        s.insert(dp[i]);
        if (i>=k){
            s.erase(s.find(dp[i-k]));
        }
    }

    cout << dp[n+1];
    
    return 0;
}
