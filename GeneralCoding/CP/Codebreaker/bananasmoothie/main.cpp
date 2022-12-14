#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,k;
    cin>>n>>k;

    int count = n/k;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n, greater<int>());
    int ans = 0;
    for (int i=0; i<count; i++){
        ans += max((int)0,arr[i*k+k-1]);
    }
    cout<<ans;
    
    
    return 0;
}
