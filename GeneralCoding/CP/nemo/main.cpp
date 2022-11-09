#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int p[50005];
int r[50005];

int find_set(int x){
    if (p[x] == x) return x;  return p[x] = find_set(p[x]);
}
bool same_set(int a, int b) {
    return find_set(a) == find_set(b);
}
void merge_set(int a, int b) {
    if (!same_set(a,b)){
        p[find_set(a)] = find_set(b);
    }
}

int find_set_r(int x){
    if (r[x] == x) return x;  return r[x] = find_set_r(r[x]);
}
bool same_set_r(int a, int b) {
    return find_set_r(a) == find_set_r(b);
}
void merge_set_r(int a, int b) {
    if (!same_set_r(a,b)){
        r[find_set_r(a)] = find_set_r(b);
    }
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,e;
    cin>>n>>e;
    vector<pair<int, pair<int,int>>> open;
    vector<pair<int, pair<int,int>>> close;
    vector<pair<pair<int,int>, pair<int,int>>> query;
    for (int i=0; i<e; i++){
        int a,b,o,c;
        cin>>a>>b>>o>>c;
        open.push_back({o, {a,b}});
        close.push_back({c, {a,b}});

    }
    for (int i=0; i<=n; i++){
        p[i] = i;
    }

    int tc;
    cin>>tc;
    for (int i=0; i<tc; i++){
        int x,y,t;
        cin>>x>>y>>t;
        query.push_back({{t,i}, {x,y}});
    }

    sort(open.begin(), open.end());
    sort(close.begin(), close.end(), greater<pair<int, pair<int,int>>>());
    sort(query.begin(), query.end());

    // for (int i=0; i<close.size(); i++){
    //     cout<<close[i].first<<' ';
    // }
    // cout<<'\n';
    int counter = 0;
    vector<pair<int,char>> ans;
    for (int i=0; i<e; i++){
        while (query[counter].first.first < open[i].first){
            if (same_set(query[counter].second.first, query[counter].second.second)){
                ans.push_back({query[counter].first.second, 'Y'});
            }
            else{
                ans.push_back({query[counter].first.second, 'N'});
            }
            // cout<<i<<' '<<counter<<'\n';
            // for (int j =0; j<=n; j++){
            //     cout<<find_set(j)<<' ';
            // }
            // cout<<endl;
            counter++;
        }

        merge_set(open[i].second.first, open[i].second.second);
    }
    for (int i=0; i<=n; i++){
        r[i] = i;
    }
    int counter2 = tc-1;
    for (int i=0; i<e; i++){
        while(query[counter2].first.first > close[i].first){
            if (same_set_r(query[counter2].second.first, query[counter2].second.second)){
                ans.push_back({query[counter2].first.second, 'Y'});
            }
            else{
                ans.push_back({query[counter2].first.second, 'N'});
            }
            // for (int j =0; j<=n; j++){
            //     cout<<find_set_r(j)<<' ';
            // }
            // cout<<endl;
            counter2--;
        }
        merge_set_r(close[i].second.first, close[i].second.second);
    }
    for (int i=counter; i<=counter2; i++){
        ans.push_back({query[i].first.second, 'Y'});
    }
    sort(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i].second<<'\n'; 
    }
    return 0;
}