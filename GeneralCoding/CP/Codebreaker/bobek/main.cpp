#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n,m;
int arr[45];
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    cin>>n>>m;
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int total = 0;

    for (int i=1; i<=n; i++){
        int l=0, r=0;
        int sum = 0;

        while (r<=n){
            if ((r-l) < i){
                sum += arr[r];
                r++;
                continue;
            }

            if (sum <=m) total++;
            sum -= arr[l];
            l++;
        }

        cout<<i<<' '<<total<<'\n';
    }

    cout<<total+1;
    return 0;
}
