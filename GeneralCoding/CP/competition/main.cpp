#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    int n,a,b;
    cin>>n>>a>>b;

    int A[n];
    int B[n];

    for (int i=0; i<n; i++){
        cin>>A[i];
    }

    for (int i=0; i<n; i++){
        cin>>B[i];
    }

    pair<int,int> arr[n];

    for (int i=0; i<n; i++){
        arr[i] = make_pair(A[i]-B[i], i);
    }

    sort (arr, arr+n, greater<pair<int,int>>());

    int ans = 0;
    for (int i=0; i<a; i++){
        ans += A[arr[i].second];
    }

    for (int i=a; i<n; i++) {
        ans += B[arr[i].second];
    }

    cout<<ans;




    
    
    return 0;
}
