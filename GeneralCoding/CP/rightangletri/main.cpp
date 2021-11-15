#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n;
    cin>>n;

    for (int i=1; i<=n; i++){
        for (int p=0; p<i; p++){
            cout<<"*";
        }
        cout<<'\n';
    }
    
    
    return 0;
}
