#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi;
    int n;
    cin>>n;
    int arr[n][n];
    for (int i=0; i<n; i++){
        for (int p=0; p<n; p++){
            cin>>arr[n][p];
        }
    }

    int a2 = arr[2][1] - arr[2][0];
    int a1 = arr[1][0] - a2;

    cout<<a1;
    for (int i=1; i<n; i++){
        cout<<' '<<arr[i][0]-a1;
    }


    
    return 0;
}
