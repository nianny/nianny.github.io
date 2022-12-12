#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n,m;
vector<int>P[500010];
int arr[500010];
bool ispossible(int x){
    for (int i=0; i<m; i++){
        if (arr[i] < x) return false;
    }
    bool flag = false;
    for (int i=0; i<n; i++){
        if (P[i].size() >= 2){
            if (P[i][P[i].size()-2] >=x){
                flag = true;
            }
        }
    }
    // cout<<x<<' '<<flag<<'\n';
    return flag;
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;

    cin>>n>>m; //n shops, m friends
    for (int i=0; i<n; i++){ //shop
        for (int p=0; p<m; p++){ //friend
            int a;
            cin>>a;
            P[i].push_back(a);
            arr[p] = max(arr[p], a);
        }
    }
    for (int i=0; i<n; i++){
        sort(P[i].begin(), P[i].end());
    }

    int low=0;
    int high=1e9;
    int mid;

    // for (int i=0; i<m; i++){ //friends
    //     cout<<arr[i]<<' ';
    // }
    // cout<<'\n';

    // for (int i=0; i<n; i++){ //shops
    //     // for (auto j:P[i]){
    //     //     cout<<j<<' ';
    //     // }
    //     cout<<P[i][P[i].size()-2]<<' ';
    //     // cout<<'\n';
        
    // }
    // cout<<'\n';


    while(high-low > 1){
        mid = (low+high)/2;
        if (ispossible(mid)){
            low = mid;
        }
        else{
            high = mid;
        }
    }

    cout<<low;
    
    return 0;
}
