#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi
    int n,a,b;
    cin>>n>>a>>b;
    pair<int,int> arr[n];
    for (int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        arr[i] = make_pair(abs(x-a)+abs(y-b), i+1);
    }
    stable_sort(arr, arr+n);
    for (int i=0; i<n; i++){
        cout<<arr[i].second<<' ';
    }
    
    return 0;
}
