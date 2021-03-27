#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        int n;
        cin>>n;
        int arr[n];
        int ans = 0;
        for (int p=0; p<n; p++){
            cin>>arr[p];
        }
        for (int p=0; p<n-1; p++){
            int minimum = arr[p];
            int index = p;
            for (int m=p; m<n; m++){
                if (minimum > arr[m]){
                    minimum = arr[m];
                    index = m;
                }
            }
            reverse(arr+p, arr+index+1);
            ans += index - p + 1;


        }
        cout<<"Case #"<<i+1<<": "<<ans<<'\n';
    }
    return 0;
}