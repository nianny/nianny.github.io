#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
int arr[500005];
int n,k;

int dp(int x){
    if (x<=n-k+1){
        int maximum = 0;
        for (int i=x;i<=n-k+1;i++){
            maximum = max(maximum,arr[i]);
        }
        return maximum;
    }
    int maximum = 0;
    for (int i=x+1; i<=x+k; i++){
        maximum = max(maximum, dp(i));
    }
    return maximum;
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
   
    cin>>n>>k;

    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<dp(-1);


    
    
    return 0;
}

/*
5 2
2 -10 2 -6 5

*/