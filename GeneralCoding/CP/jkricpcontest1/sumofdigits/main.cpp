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
    for (int i=1; i<=n/4; i++){
        // cout<<i<<'\n';
        if ((n-i*4)%7 == 0){
            for (int p=0; p<i; p++){
                cout<<"4";
            }
            for (int p=0; p<(n-i*4)/7; p++){
                cout<<"7";
            }
            return 0;
        }
    }
    cout<<"-1";
    
    return 0;
}
