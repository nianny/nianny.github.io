#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,s;
    cin>>n>>s;
    int pos[n+5];
    int arr[n+5];
    int maxsum[n+5];
    memset(maxsum, 0, sizeof maxsum);

    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        pos[a] = i;
    }

    for (int i=0; i<s; i++){
        memset(maxsum, 0, sizeof maxsum);
        for (int p=1; p<=n; p++){
            cin>>arr[p];
        }
        maxsum[1] = 1;
        for (int p=2; p<=n; p++){
            for (int j=1; j<p; j++){
                // cout<<j<<' '<<arr[j]<<' '<<p<<arr[p]<<'\n';
                if (pos[arr[j]] < pos[arr[p]]){
                    // cout<<j<<' '<<arr[j]<<' '<<p<<arr[p]<<'\n';
                    maxsum[p] = max(maxsum[p], maxsum[j]+1);
                }
            }

            if (maxsum[p] == 0){
                maxsum[p] = 1;
            }
        }

        cout<<*max_element(maxsum, maxsum+n+1)<<'\n';
    }
    
    return 0;
}
