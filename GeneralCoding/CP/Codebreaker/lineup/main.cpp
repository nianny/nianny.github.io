#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
map<int,int> counter;
set<int> current;
set<int> breeds;
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    vector<pair<int, int>> v;

    
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
        breeds.emplace(b);
    }
    sort(v.begin(), v.end());

    int l = 0;
    int r = 0;
    int ans = LLONG_MAX;
    while (r<=n){
        if (current.size() == breeds.size()){
            ans = min(ans, v[r-1].first - v[l].first);
            if (counter[v[l].second] == 1){
                counter[v[l].second]--;
                current.erase(v[l].second);
            }
            else{
                counter[v[l].second]--;
            }
            l++;
        }
        else if(current.size() < breeds.size()){
            if (counter[v[r].second] == 0){
                counter[v[r].second] = 1;
                current.insert(v[r].second);
            }
            else{
                counter[v[r].second]++;
            }
            r++;
            continue;
        }
    }

    cout<<ans;
    return 0;
}
