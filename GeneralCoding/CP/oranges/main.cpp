#include <bits/stdc++.h>
using namespace std;
#define int long long



bool comparator(pair<int,int>a, pair<int,int>b){
    return a.first > b.first;
}

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    pair<int, int> arr[n];
    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        arr[i] = make_pair(a,i+1);
    }
    sort(arr, arr+n, comparator);
    if (arr[0].second < arr[1].second){
        cout<<arr[0].second<<' '<<arr[1].second;
    }
    else {
        cout<<arr[1].second<<' '<<arr[0].second;
    }
    return 0;
}
