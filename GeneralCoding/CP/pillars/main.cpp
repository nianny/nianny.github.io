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
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    if (n%2 == 1){
        for (int i=1; i<=n/2; i++){
            cout<<i<<'\n';
        }

        for (int i=n/2; i>0; i--){
            cout<<i<<'\n';
        }
        cout<<0;
    }

    else {
        for (int i=1; i<=n/2; i++){
            cout<<i<<'\n';
        }
        for (int i=n/2-1; i>0; i--){
            cout<<i<<'\n';
        }
        cout<<0;
    }




    return 0;
}
