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
    int ans = 0;
    for (int i=1; i<=n+1; i++){
        ans += abs(arr[i] - arr[i-1]);
    }
    for (int i=1; i<=n; i++){
        int indi = ans;
        indi -= abs(arr[i-1]-arr[i]);
        indi -= abs(arr[i+1] - arr[i]);
        indi += abs (arr[i-1] - arr[i+1]);
        cout<<indi<<'\n';
    }
    return 0;
}