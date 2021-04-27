#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n,q;
    char str[2*n];
    cin>>n>>q;
    for (int i=0; i<2*n; i++){
        cin>>str[i];
    }
    
    for (int i=0; i<q; i++){
        int t,a,b;
        cin>>t>>a>>b;
        if (t==1){
            swap(str[a-1], str[b-1]);
        }
        else{
            
        }
    }
    return 0;
}