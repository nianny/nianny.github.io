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
    deque<int>arr(n);
    // int sum = 0;
    for (int i=0; i<n; i++){
        cin>>arr[i];
        // sum += arr[i];
    }

    // int pieces = 0;
    int cuts = k-n;
    sort(arr.begin(), arr.end(), greater<int>());

    deque<int>dq;
    for (int i=0; i<cuts; i++){
        
    }
    
    
    return 0;
}
