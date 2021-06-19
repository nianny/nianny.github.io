#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi
    int n,k;
    cin>>n>>k;
    for (int i=0; i<k; i++){
        if (n%200 == 0){
            n /= 200;
        }
        else{
            n = stoll(to_string(n)+"200");
        }
    }
    cout<<n;
    
    return 0;
}
