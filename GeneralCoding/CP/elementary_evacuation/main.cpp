#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
vector<int> arr[1000005];
// bool hold[1000005];
int ans[1000005];

int dp(int a){
    if (ans[a] != -1) return ans[a];
    if (arr[a].size() == 0) return 0;

    for (int i=0; i<arr[a].size(); i++){
        ans[a] = max(ans[a], dp(arr[a][i]) + 1);
    }

    return ans[a];
}


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n, m;
    cin>>n>>m;
    memset(ans, -1, sizeof ans);
    // memset(wait, false, sizeof(wait));

    // int ans[n];

    for (int i=1; i<=m; i++){
        int a,b;
        cin>>a>>b;
        // hold[a] = true;
        arr[a].push_back(b);
    }

    // for (int i=1; i<=n; i++){
    //     // cout<<arr[i].size()<<endl;
        
    //     if (!hold[i]){
    //         // cout<<ans[i]<<endl;
    //         for (int p=0; p<arr[i].size(); p++){
    //             ans[arr[i][p]] = max(ans[arr[i][p]], ans[i]+1);
    //         }
    //     }
    // }

    // for (int i=1; i<=n; i++){
    //     // cout<<arr[i].size()<<endl;
        

    //     // cout<<ans[i]<<endl;
    //     for (int p=0; p<arr[i].size(); p++){
    //         ans[arr[i][p]] = max(ans[arr[i][p]], ans[i]+1);

    //         cout<<arr[i][p]<<' '<<ans[i]+1<<' '<<ans[arr[i][p]]<<endl;
    //     }

    // }

    for (int i=1; i<=n; i++){
        cout<<dp(i)<<' ';
    }
    
    return 0;
}

/*
5 3 
1 4
2 3 
4 5
*/

/*
4 6
1 2
1 3
1 4
2 3
2 4
3 4
*/