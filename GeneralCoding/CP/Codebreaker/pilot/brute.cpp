#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,q;
    cin>>n>>q;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    for (int i=0; i<q; i++){
        int a;
        cin>>a;
        int total = 0;
        int current = 0;
        for (int p=0; p<n; p++){
            if (arr[p] <= a){
                current ++;
                // high = max(high, current);
            }
            else{
                total += current * (current+1)/2;
                // cout<<p<<' '<<total<<'\n';
                current = 0;
            }
        }
        total += current * (current+1)/2;

        cout<<total<<'\n';
    }
    
    
    return 0;
}
