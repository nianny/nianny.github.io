#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi
    int n;
    cin>>n;
    for (int i=1; i<2*n; i++){
        for (int p=1; p<2*n; p++){
            cout<<min(min(i,p), min(2*n-i, 2*n-p));
            if (p != 2*n-1){
                cout<<' ';
            }
        }
        if (i!=2*n-1){
            cout<<'\n';
        }
    }
    
    return 0;
}
