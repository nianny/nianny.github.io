#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,l,t;
    cin>>n>>l>>t;

    int arr[n+1];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    arr[n] = l;
    sort(arr, arr+n+1);


    int d = 0;
    int ans = 0;
    for (int i=0; i<n; i++){
        // cout<<i<<' '<<arr[i]<<' '<<d<<'\n';
        if ((arr[i] - d) > t){
            cout<< -1;
            return 0;
        }

        if ((arr[i] - d) <= t && (arr[i+1]-d) > t){
            ans++;
            d = arr[i];
        }
    }
    if (l-d > t){
        cout<< -1;
        return 0;
    }

    cout<<ans;
    
    return 0;
}
