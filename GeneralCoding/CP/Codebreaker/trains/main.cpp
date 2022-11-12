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
    int arr[n+5];
    for (int i=1; i<=n; i++){
        cin>>arr[i];
    }
    arr[0] = 10e9;
    arr[n+1] = 0;

    int dist[n+5];
    dist[0] = 0;
    for (int i=1;i<=n+1; i++){
        dist[i] = LLONG_MAX;
    }
    for (int i=1; i<= n+1; i++){
        for (int p=0; p<i; p++){
            if (arr[p] >= arr[i]){
                dist[i] = min(dist[i], dist[p] + (i-p)*(i-p));
            }
        }
    }
    cout<<dist[n+1];
    return 0;
}
