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
    for (int hmm = 0; hmm < t; hmm++){
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++){
            cin>>arr[i];
        }
        int count = 0;
        for (int i=0; i<n; i++){
            for (int p=i+1; p<n; p++){
                if (arr[p] < arr[i]){
                    count ++;
                }
            }
        }

        cout<<count<<'\n';
    }
    
    return 0;
}
