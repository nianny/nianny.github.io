#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[1000010][2];

int beeg[1000010][2];
int n,k;
// int dp(int index, int table){
//     int ans = 0;
//     ans = min(dp(index-1, table)+)

// }


int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    memset(arr,0,sizeof(arr));
    

    cin>>n>>k;

    for (int i=0; i<n; i++){
        cin>>beeg[i][0];
    }
    for (int i=0; i<n; i++){
        cin>>beeg[i][0];
    }

    arr[0][0]=beeg[0][0];
    arr[0][1]=beeg[0][1];


    for (int i=1; i<=n; i++){
        for (int p=0; p<2; p++){
            arr[i][p] = max(arr[i-1][p]+arr[i][p], arr[i][(p+1)%2] + arr[i][p]-1 - k);
        }
    }

    cout<<max(arr[n][0], arr[n][1]);

    return 0;
}