#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n,m;
    cin>>n>>m;
    for (int i=1; i<m; i++){
        if (n%2 == 0){
            n = n/2;
        }
        else {
            n = (3*n)+1;
        }

        if (n==1){
            cout<<"-1";
            return 0;
        }
        // cout<<n<<' ';
    }
    cout<<n;
    return 0;
}