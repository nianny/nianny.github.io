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

    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort (arr, arr+n);

    int l=0;
    int r=0;
    int ans=LLONG_MAX;
    int indi;
    deque<pair<int,int>> dq; //value, left
    while(r<n-1){
        if ((r-l+1) < n-k){
            while(!dq.empty() && dq.back().first > arr[r+1]-arr[r]){
                dq.pop_back();
            }
            dq.push_back({arr[r+1]-arr[r], r});
            r++;
            continue;
        }

        while(!dq.empty() && dq.front().second < l) dq.pop_front();
        indi = arr[r] - arr[l] + dq.front().first;
        // cout<<l<<' '<<r<<' '<<indi<<'\n';
        ans = min(ans, indi);

        l++;
    }

    cout<<ans;
    
    return 0;
}
