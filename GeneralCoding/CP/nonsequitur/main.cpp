#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi
    int n;
    int s,e;
    cin>>n;
    cin>>s>>e;
    if (s%n != 0){
        s = s+n-s%n;
    }
    for (int i=s; i<=e; i+= n){
        cout<<i<<'\n';
    }
    
    return 0;
}
