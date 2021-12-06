#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n,m;
    cin>>n>>m;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    bool flag = false;
    if (n > 1 && arr[0] > arr[1]){
        if ((arr[0] - arr[1]) < m){
            flag = true;
        }
    }
    else if (n > 1 && arr[0] <= arr[1]){
        if ((arr[1] - arr[0]) <= m+1){
            flag = true;
        }
    }

    if (flag){
        cout<<n-1;
    }
    else {
        cout<<0;
    }


    return 0;
}
