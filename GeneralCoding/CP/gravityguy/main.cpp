#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n, greater<int>());

    for (int i=0; i<n; i++){
        cout<<arr[i]<<'\n';
    }
    
    return 0;
}
