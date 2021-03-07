#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    int arr[n];
    int lis[n];
    memset(lis, 0, sizeof lis);

    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    for (int i=0; i<n; i++){
        for (int p=0; p<i; p++){
            if (arr[i] > arr[p]){
                lis[i] = max(lis[i], lis[p]+1);
                //cout<<i<<' '<<p<<' '<<lis[p]<<'\n';
            }
        }

        if (lis[i] == 0) lis[i] = 1;
    }

    int ans = 0;

    for (int i=0; i<n; i++){
        ans = max(ans, lis[i]);
    }
    cout<<ans;
    return 0;
}