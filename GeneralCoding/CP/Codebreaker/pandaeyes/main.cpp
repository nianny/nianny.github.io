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
    vector<pair<int,int>> v;
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({b,a});
    }

    sort(v.begin(), v.end());
    int ans = 0;
    int time = 0;
    int counter = 0;
    while (counter < v.size()){
        if (v[counter].second >= time){
            time = v[counter].first;
            ans++;
        }
        counter++;
    }

    cout<<ans;
    
    
    return 0;
}
