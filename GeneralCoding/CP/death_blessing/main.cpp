#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    hallo;
    
    int t;
    cin>>t;

    vector<int> ans;
    for (int m=0; m<t; m++){
        int n;
        cin>>n;
        int sum = 0;
        for (int i=0; i<n; i++){
            int x;
            cin>>x;
            sum += x;
        }
        int arr[n];
        int largest = 0;
        for (int i=0; i<n; i++){
            cin>>arr[i];
            sum += arr[i];
            largest = max(largest, arr[i]);
        }
        sum -= largest;
        ans.push_back(sum);
    }

    for (auto it: ans){
        cout<<it<<endl;
    }
    return 0;
}
