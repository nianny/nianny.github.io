#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n,m;
int arr[45];
vector<int>arrb;
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    cin>>n>>m;
    for (int i=0; i<n; i++){
        cin>>arr[i];
        if (i >= n/2){
            arrb.push_back(arr[i]);
        }
    }
    vector<int> front;
    for (int i=0; i<(1<<(n/2)); i++){
        int sum = 0;
        for (int p=0; p<n/2; p++){
            if (i & (1<<p)){
                sum += arr[p];
            }
        }
        // cout<<i<<' '<<sum<<'\n';
        front.push_back(sum);
    }
    vector<int>back;
    for (int i=0; i<(1<<arrb.size()); i++){
        int sum = 0;
        for (int p=0; p<arrb.size(); p++){
            if (i & (1<<p)){
                sum += arrb[p];
            }
        }
        // cout<<i<<' '<<sum<<'\n';
        back.push_back(sum);
    }

    sort(back.begin(), back.end());
    // for (auto i:front){
    //     cout<<i<<' ';
    // }
    // cout<<'\n';
    
    // cout<<"SIZE: "<<back.size()<<'\n';
    // for (auto i:back){
    //     cout<<i<<' ';
    // }
    // cout<<'\n';

    int ans = 0;
    for (auto i: front){
        // cout<<i<<' '<<upper_bound(back.begin(), back.end(), m-i)-back.begin()<<'\n';
        ans += upper_bound(back.begin(), back.end(), m-i)-back.begin();
        // cout<<i<<' '<<ans<<'\n';
    }
    cout<<ans;
    return 0;
}
