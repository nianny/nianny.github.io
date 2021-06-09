#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        string a;
        // scanf("%")
        cin>>a;
        int b = a[a.length()-1];
        if (b%2 == 0){
            cout<<"even"<<'\n';
        }
        else{
            cout<<"odd"<<'\n';
        }
    }
    return 0;
}