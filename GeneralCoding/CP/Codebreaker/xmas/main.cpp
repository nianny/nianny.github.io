#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int arr[20010];
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;

    for (int i=1; i<=n; i++){
        int x;
        cin>>x;
        arr[x] = i;
    }

    for (int i=1; i<=n; i++){
        cout<<arr[i]<<'\n';
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}
