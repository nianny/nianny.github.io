#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi
    int n;
    cin>>n;
    int sum = 0;
    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        if (a>10){
            sum += (a-10);
        }
    }
    cout<<sum;
    
    return 0;
}
