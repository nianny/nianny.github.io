#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int p[1005];

int find(int x){
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void join(int x, int y){
    p[find(x)] = find(y);
}

bool same_set(int x, int y){
    return find(x) == find(y);
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    vector<pair<int,int>> points(n);
    vector<pair<int, pair<int,int>>> edges;
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        points[i] = {a,b};
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            // if (i == j) continue;
            edges.push_back({(points[i].first - points[j].first)*(points[i].first - points[j].first) + (points[i].second - points[j].second)*(points[i].second - points[j].second), {i,j}});
        }
    }

    sort(edges.begin(), edges.end());
    vector<pair<int, pair<int,int>>> new_edges;

    bool possible = true;
    int ans = 0;
    while (possible){
        for (int i=0; i<n; i++){
            p[i] = i;
        }
        int counter = 0;
        for (auto it: edges){
            if (!same_set(it.second.first, it.second.second)){
                join(it.second.first, it.second.second);
                // cout<<it.second.first<<" "<<it.second.second<<endl;
                counter++;
            }
            else{
                new_edges.push_back(it);
            }
        }
        if (counter < n-1){
            possible = false;
        }
        else{
            ans++;
            edges = new_edges;
            new_edges.clear();
        }

        // cout<<counter<<endl;
    }
    cout<<ans;


    /*
    Hallooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    */
    return 0;
}

