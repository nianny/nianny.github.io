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
            if (!toggle){
                for (int i=1; i<=n; i++){
                    ss[i] = ss[i-1] + arr[i];
                }
                toggle = true;
            }
            int a,b;
            cin>>a>>b;
            cout<<ss[b]-ss[a-1]<<'\n';
        }
    }
    return 0;
}
