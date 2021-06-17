#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        unsigned long long n;
        cin>>n;
        cout<<(int)cbrtl(n)<<'\n';
    }
    return 0;
}
