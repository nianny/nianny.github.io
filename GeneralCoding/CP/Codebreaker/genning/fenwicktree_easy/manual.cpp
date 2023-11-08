#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int arr[1000010];
int ss[1000010];
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>arr[i];
    }

    int m;
    cin>>m;
    bool toggle = false;
    for (int i=0; i<m; i++){
        int t;
        cin>>t;

        if (t==1){
            int a,b;
            cin>>a>>b;
            arr[a] = b;
        }
        else {
            int a,b;
            cin>>a>>b;
            int ans = 0;
            for (int i=a; i<=b; i++){
                ans += arr[i];
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
