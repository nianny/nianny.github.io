#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,c;
    cin>>n>>c;
    vector<pair<int,int>> a;
    vector<pair<int,int>> b;

    for (int i=0; i<n; i++){
        int s,v;
        cin>>s>>v;

        if (i >= n/2){
            b.push_back({s,v});
        }
        else{
            a.push_back({s,v});
        }
    }

    vector<pair<int,int>> front,back; //weight, importance
    for (int i=0; i<(1<<n/2); i++){
        int sum = 0;
        int weight = 0;
        for (int p=0; p<n/2; p++){
            if (i & (1<<p)){
                weight += a[p].first;
                sum += a[p].second;
            }
        }
        front.push_back({weight, sum});
    }
    for (int i=0; i<(1<<b.size()); i++){
        int sum = 0;
        int weight = 0;
        for (int p=0; p<b.size(); p++){
            if (i & (1<<p)){
                weight += b[p].first;
                sum += b[p].second;
            }
        }
        back.push_back({weight, sum});
    }
    sort(back.begin(), back.end());
    // for (auto [a,b]: front){
    //     cout<<a<<' '<<b<<'\n';
    // }
    // cout<<'\n';

    // for (auto [a,b]: back){
    //     cout<<a<<' '<<b<<'\n';
    // }
    // cout<<'\n';
    vector<int>prefixmax;
    vector<int>bs;

    int maximum = 0;
    for (auto [x,y]: back){
        maximum = max(maximum, y);
        prefixmax.push_back(maximum);
        bs.push_back(x);
    }
    // for (auto i: prefixmax){
    //     cout<<i<<' ';
    // }
    // cout<<'\n';

    int ans = 0;
    for (auto [x,y]: front){
        int remaining = c-x;
        if (remaining < 0) continue;
        int other = prefixmax[upper_bound(bs.begin(), bs.end(), remaining) - bs.begin()-1];
        // cout<<x<<' '<<y<<' '<<other<<'\n';
        ans = max(ans, y + other);
    }
    cout<<ans;

    
    
    
    return 0;
}
