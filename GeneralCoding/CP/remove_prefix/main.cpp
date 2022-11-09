#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int t;
    cin>>t;
    for (int hal =0; hal<t; hal++){
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++){
            cin>>arr[i];
        }
        int index = 0;
        for (int i=n-1; i>=0; i--){
            bool dup = false;
            for (int p=i+1; p<n; p++){
                if (arr[i] == arr[p]){
                    dup = true;
                    break;
                }
            }

            if (dup){
                index = i+1;
                break;
            }
        }
        cout<<index<<'\n';
    }
    
    return 0;
}
