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

    int maxsum[n+5];
    memset(maxsum, 0, sizeof(maxsum));
    vector<int> pos;
    for (int i=1; i<=n; i++){
        if (maxsum[i-1] < 0){
            maxsum[i] = arr[i];
            pos.push_back(i);
            cout<<i<<'\n';
        }
        else{
            maxsum[i] = maxsum[i-1] + arr[i];
        }
    }
    int ans = 0;

    for (int i=0; i<=n; i++){
        cout<<maxsum[i]<<' ';
    }
    cout<<'\n';

    for(int i=2; i<=n; i++){
        int first = *max_element(maxsum, maxsum+i);
        
        auto second = max_element(maxsum+i, maxsum+n+1);
        auto position = lower_bound(pos.begin(), pos.end(), i);
        int sv;
        if (position != pos.end() && *position < second-maxsum){
            sv = *second;
        }
        else{
            sv = *second-maxsum[i];
        }
        ans = max(ans, first+sv);
        // cout<<i<<' '<<first<<' '<<sv<<'\n';
    }

    ans = max(ans, *max_element(maxsum, maxsum+n+1));

    

    cout<<ans<<endl;
    
    return 0;
}