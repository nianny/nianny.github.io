#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi;
    int n;
    cin>>n;
    int arr[n];
    int sum =0;
    for (int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    int height = sum/n;
    int ans = 0;
    for (int i=0; i<n; i++){
        if (arr[i]<height){
            ans += height-arr[i];
        }
    }

    cout<<ans;

    
    return 0;
}
