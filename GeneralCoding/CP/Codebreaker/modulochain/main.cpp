#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int mod = 1e9+7;

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    //sum
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += arr[i]%mod;
        sum %= mod;
    }

    cout<<sum<<' ';

    //product
    cout<<((arr[0]%mod) * (arr[n-1]%mod))%mod<<' ';

    sum = arr[0];
    for (int i=1; i<n; i++){
        sum += mod-(arr[i]%mod);
        sum %= mod;
    }

    cout<<sum<<' ';
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

