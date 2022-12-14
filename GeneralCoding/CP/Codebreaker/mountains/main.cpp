#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;

    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = 0;
    for (int i=1; i<n-1; i++){
        int less =0;
        int more = 0;
        for (int p=0; p<i; p++){
            if (arr[p] < arr[i]){
                less++;
            }
        }

        for (int p=i+1; p<n; p++){
            if (arr[p] < arr[i]) more++;
        }

        ans += less*more;
    } 
    cout<<ans;
    
    return 0;
}
