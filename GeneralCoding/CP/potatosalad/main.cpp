#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n,d;
    cin>>n>>d;
    int arr[n];

    for (int i=0; i<n; i++){ 
        cin>>arr[i];
    }

    sort(arr, arr+n, greater<int>());
    int ans = 0;
    for (int i=0; i<d; i++){
        ans += arr[i];
    }
    cout<<ans;
    
    
    return 0;
}
