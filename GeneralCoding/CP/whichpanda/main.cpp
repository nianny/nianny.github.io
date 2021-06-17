#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;

    int arr[n];
    int save[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
        save[i] = arr[i];
    }
    sort(arr, arr+n, greater<int>());
    if (arr[0] == arr[1]){
        cout<<"MMMMMEEEEOOOOOWWWW!!!!!";
    }
    else{
        cout<<*lower_bound(save, save+n, arr[0]);
    }
    return 0;
}
