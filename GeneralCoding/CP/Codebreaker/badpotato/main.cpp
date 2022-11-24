#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    int arr[n+10];
    memset(arr, 0, sizeof arr);

    for (int i=1; i<=n; i++){
        int a;
        cin>>a;
        if (a == -1) arr[i] = 0;
        else{
            arr[i] = max(arr[i-1] + a, a);
        }
    }

    cout<<*max_element(arr, arr+n+1);
    
    return 0;
}
