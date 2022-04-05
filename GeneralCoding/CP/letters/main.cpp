#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n, m;
    cin >> n >> m;

    int arr[n+5];
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    int ss[n+5];

    ss[0] = 0;
    for (int i=1; i<=n; i++){
        ss[i] = ss[i-1] + arr[i];
    }


    for (int i=0; i<m; i++){
        int num;
        cin>>num;

        int pos = lower_bound(ss, ss+n+1, num) - ss;
        // cout<<pos<<endl;
        cout<<pos<<' '<<num-ss[pos-1]<<endl;

    }
    
    
    return 0;
}
