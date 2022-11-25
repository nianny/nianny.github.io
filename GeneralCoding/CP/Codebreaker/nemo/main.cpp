#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int p[50010];

int find_set(int x){
    if (p[x] == x) return x;
    p[x] = find_set(p[x]); // path compressions
    return p[x];
}

bool same_set(int a, int b){
    return find_set(a) == find_set(b);
}

void merge_set(int a, int b){
    p[find_set(a)] = find_set(b);
}
    
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,e;
    cin>>n>>e;

    for (int i=0; i<n; i++){
        p[i] = i;
    }

    vector<pair<int, pair<int,int>>> open;
    vector<pair<int, pair<int,int>>> close;

    for (int i=0; i<e; i++){
        int a,b,o,c;
        cin>>a>>b>>o>>c;
        open.push_back({o, {a,b}});
        close.push_back({c, {a,b}});
    }

    int tc;
    cin>>tc;
    deque<pair<int, pair<int,pair<int,int>>>> query;
    for (int i=0; i<tc; i++){
        int x,y,t;
        cin>>x>>y>>t;
        query.push_back({t, {i, {x,y}}});
    }

    sort(open.begin(), open.end());
    sort(close.begin(), close.end(), greater<pair<int,pair<int,int>>>());
    sort(query.begin(), query.end());

    vector<pair<int,bool>> ans;
    for (auto i: open){
        while (!query.empty() && query.front().first < i.first){
            auto c = query.front();
            query.pop_front();

            if (same_set(c.second.second.first, c.second.second.second)){
                ans.push_back({c.second.first, true});
            }
            else{
                ans.push_back({c.second.first, false});
            }
        }

        merge_set(i.second.first, i.second.second);
    }

    while(!query.empty() && query.front().first <= close.back().first){
        auto c = query.front();
        query.pop_front();
        if (same_set(c.second.second.first, c.second.second.second)){
            ans.push_back({c.second.first, true});
        }
        else{
            ans.push_back({c.second.first, false});
        }
    }

    for (int i=0; i<n; i++){
        p[i] = i;
    }

    for (auto i: close){
        while(!query.empty() && query.back().first > i.first){
            auto c = query.back();
            query.pop_back();

            if (same_set(c.second.second.first, c.second.second.second)){
                ans.push_back({c.second.first, true});
            }
            else{
                ans.push_back({c.second.first, false});
            }
        }

        merge_set(i.second.first, i.second.second);
    }

    sort(ans.begin(), ans.end());

    for (auto i: ans){
        if (i.second){
            cout<<"Y"<<'\n';
        }
        else{
            cout<<"N"<<'\n';
        }
    }
    
    return 0;
}
