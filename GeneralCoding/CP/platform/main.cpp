#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi
    int n;
    cin>>n;
    for (int i=n-1; i>=0; i--){
        for (int p=0; p<i; p++){
            cout<<' ';
        }
        cout<<'/';
        for (int p=0; p<2*(n-1-i); p++){
            cout<<' ';
        }
        cout<<'\\';
        cout<<'\n';
    }
    for (int i=0; i<n; i++){
        for (int p=0; p<i; p++){
            cout<<' ';
        }
        cout<<'\\';
        for (int p=2*(n-1-i)-1; p>=0; p--){
            cout<<' ';
        }
        cout<<'/';
        cout<<'\n';
    }
    
    return 0;
}
