#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n;
int fen1[300010];
int fen2[300010];
void update1(int x, int v){
    while (x <= n){
        fen1[x] += v;
        x += x&-x;
    }
}
void update2(int x, int v){
    // x = n+1-x;
    while (x <= n){
        fen2[x] += v;
        x += x&-x;
    }
}

int query1(int r){
    long long result = 0;

    while (r){
        result += fen1[r];
        r -= r & -r;
    }

    return result;
}

int query2(int r){
    // r = n+1-r;
    long long result = 0;

    while (r){
        result += fen2[r];
        r -= r & -r;
    }

    return result;
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    // int n;
    cin>>n;

    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int cop[n];
    copy(arr, arr+n, cop);
    sort(cop, cop+n);

    for (int i=0; i<n; i++){
        arr[i] = lower_bound(cop, cop+n, arr[i])-cop+1;
    }
    // for (int i=0; i<n; i++){
    //     cout<<arr[i]<<' ';
    // }
    // cout<<'\n';

    for (int i=0; i<n; i++){
        update2(arr[i], 1);
    }

    // for (int i=0; i<=n; i++){
    //     cout<<fen1[i]<<' ';
    // }
    // cout<<'\n';
    // // cout<<query1(0)<<'\n';

    // for (int i=0; i<=n; i++){
    //     cout<<fen2[i]<<' ';
    // }
    // cout<<'\n';
    // cout<<arr[0]<<' '<<query1(arr[0])<<'\n';
    int ans = 0;
    for (int i=0; i<=n-1; i++){
        ans += query1(arr[i]-1)*query2(arr[i]-1);
        // cout<<i<<' '<<arr[i]<<' '<<query1(arr[i]-1)<<' '<<query2(arr[i]-1)<<'\n';

        update1(arr[i], 1);
        update2(arr[i], -1);
    }
    // cout<<'\n';


    
    // for (int i=1; i<n-1; i++){
    //     int less =0;
    //     int more = 0;
    //     for (int p=0; p<i; p++){
    //         if (arr[p] < arr[i]){
    //             less++;
    //         }
    //     }

    //     for (int p=i+1; p<n; p++){
    //         if (arr[p] < arr[i]) more++;
    //     }

    //     ans += less*more;
    // } 
    cout<<ans;
    
    return 0;
}
