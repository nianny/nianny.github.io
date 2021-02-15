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

    for (int i=0; i<2; i++){
        //bool side = i; //true is left, false is right
        int result = beeg[0][i];
        for (int p=1; p<n; p++){
            if (beeg[p][(i+1)%2]  > )
        }
    }

    return 0;
}