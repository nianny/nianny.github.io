#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n,q;
    cin>>n;
    bool swapi = false;
    char arr[2][n];
    for (int i=0; i<2*n; i++){
        cin>>arr[i/n][i-(i/n)*n];
    }

    cin>>q;
    for (int i=0; i<q; i++){
        int t,a,b;
        cin>>t>>a>>b;
        a--;
        b--;

        if (t==1){
            // if (swapi){
            swap(arr[((a/n)+swapi)%2][a-(a/n)*n], arr[((b/n)+swapi)%2][b-(b/n)*n]);
            // for (int i=0; i<2*n; i++){
            //     cout<<arr[((i/n)+swapi)%2][i-(i/n)*n];
            // }
            // cout<<'\n';
            // }
        }
        else if (t==2){
            swapi = !swapi;
            // for (int i=0; i<2*n; i++){
            //     cout<<arr[((i/n)+swapi)%2][i-(i/n)*n];
            // }
            // cout<<'\n';
        }

    }

    for (int i=0; i<2*n; i++){
        cout<<arr[((i/n)+swapi)%2][i-(i/n)*n];
    }
    return 0;
}