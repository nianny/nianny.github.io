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

    int maxsum0[n+5];
    int maxsum1[n+5];
    memset(maxsum0, 0, sizeof(maxsum0));
    memset(maxsum1, 0, sizeof(maxsum1));

    int ans = 0;
    for (int i=1; i<=n; i++){
        memset(maxsum0, 0, sizeof(maxsum0));
        memset(maxsum1, 0, sizeof(maxsum1));
        for(int p=1; p<=i; p++){
            maxsum0[p] = max(maxsum0[p-1]+arr[p],arr[p]);
        }

        for (int p=i+1; p<=n; p++){
            maxsum1[p] = max(maxsum1[p-1]+arr[p], arr[p]);
        }

        ans = max(ans, *max_element(maxsum0, maxsum0+n+1) + *max_element(maxsum1, maxsum1+n+1));
    }

    

    cout<<ans<<endl;
    
    return 0;
}
