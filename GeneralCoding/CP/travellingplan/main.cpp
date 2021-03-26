#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    int arr[n+5];

    for (int i=1; i<=n; i++){
        cin>>arr[i];
    }
    arr[0] = 0;
    arr[n+1] = 0;
    // int ans = 0;
    for (int i=1; i<=n; i++){
        int ans = 0;
        // // if (i ==0){
        // cout<<abs(abs(arr[i+1]-arr[i]) - abs(arr[i+2]-arr[i+1]))<<'\n';
        // // }
        // // else if (i == n-1){
        // //     cout<<
        // // }
        for (int p=0; p<=n; p++){
            if (i == p){
                ans += abs(arr[i-1] - arr[i+1]);
                // cout<<arr[p]<<' '<<arr[p+1]<<'\n';
                continue;
            }
            else if (i==(p+1)){
                continue;
            }
            ans += abs(arr[p] - arr[p+1]);
            // cout<<arr[p]<<' '<<arr[p+1]<<'\n';

        }
        cout<<ans<<'\n';
        // cout<<'\n';
        // ans += abs(arr[i] - arr[i+1]);
    }
    // cout<<ans;
    return 0;
}