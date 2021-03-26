#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n,a;
    cin>>n>>a;
    int ans = n%500;
    if (ans <= a){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}