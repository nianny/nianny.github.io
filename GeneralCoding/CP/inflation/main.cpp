#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int arr[] = {7, 6, 3, 3, 4, 1, 6, 8, 3, 1};
    sort (arr, arr+10, greater<int>());
    int ans = 0;
    for (int i=0; i<10; i++){
        ans += arr[i]*i;
    }
    cout<<ans;
    return 0;
}