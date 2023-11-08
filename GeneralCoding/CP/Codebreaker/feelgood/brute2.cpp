#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int MOD = 1e9+7;
int multiplier = 1;
int arr[10];
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int a,b;
    cin>>a>>b;
    
    int b_length = log10(b)+1;
    cout<<b_length<<'\n';
    for (int p=0; p<b_length; p++){
        for (int i=0; i<10; i++){
            arr[i] = ((b+1)/10)%MOD;
        }
    }
    

    for (int i=0; i<10; i++){
        cout<<arr[i]<<'\n';
    }



    
    
    return 0;
}
