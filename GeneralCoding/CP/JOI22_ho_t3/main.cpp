#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n, hmm;

double memo[507][507][507];
// int A[507],B[507];
pair<int,int>arr[507];
double dp(int index, int k, int collab){
    if(memo[index][k][collab] >= 0) return memo[index][k][collab];
    if (k == 0) return memo[index][k][collab] = 0;
    if (index >= n) return memo[index][k][collab]=1e18;
    
    if (arr[index].second == 1e9){
        return memo[index][k][collab] = min({dp(index+1, k, collab), dp(index+1, k-1, collab) + (double)arr[index].first/collab});
    }
    return memo[index][k][collab] = min({dp(index+1, k, collab), dp(index+1, k-1, collab) + (double)arr[index].first/collab, dp(index+1, k-1, collab+1)+(double)arr[index].second/collab});
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    cin>>n>>hmm;
    for(int i = 0; i < n; i++){
        int a,b;
        cin>>a>>b;
        arr[i] = {a,b};
        if (arr[i].second == -1) arr[i].second = 1e9;
    }
    // for (int i=0; i<n; i++){
    //     cout<<arr[i].first<<' '<<arr[i].second<<'\n';
    // }
    // cout<<'\n';

    sort(arr, arr+n, [](pair<int,int>a, pair<int,int>b){
        // if (b.second == -1) return true;
        if (a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    });
    for (int i=0; i<n; i++){
        cout<<arr[i].first<<' '<<arr[i].second<<'\n';
    }
    // cout<<'\n';

    // memset(memo, -1, sizeof memo);
    for (int x=0; x<=505; x++){
        for (int y=0; y<=505; y++){
            for (int z=0; z<=505; z++){
                memo[x][y][z] = -1;
            }
        }
    }
    cout<<fixed<<setprecision(10);
    cout<<dp(0, hmm, 1)<<'\n';

    // for (int x=0; x<=n; x++){
    //     for (int y=0; y<=n; y++){
    //         for (int z=0; z<=n; z++){
    //             cout<<memo[x][y][z]<<' ';
    //         }
    //         cout<<'\n';
    //     }

    //     cout<<'\n'<<'\n';
    // }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

