#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n, greater<int>());
    int ans = 0;
    for (int i=0; i<n; i++){
        if (i %2 == 0){
            ans += arr[i];
        }
        else{
            ans -= arr[i];
        }
    }
    cout<<abs(ans);

    return 0;
}