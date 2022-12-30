#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n;
vector<int>adjlist[100010];
int min_counter, max_counter;
int minimum[100010], maximum[100010];
int ss[100010];
int pp[100010];
int hp[100010];

bool comp(vector<int> a, vector<int>b){
    return a.size() > b.size();
}
void dfs(int x, int p){
    for (auto i: adjlist[x]){
        if (i == p) continue;
        dfs(i, x);

        // if (minimum[i] == i){
        //     swap(minimum[i], minimum[x]);
        //     min_counter += 2;
        // }
    }
    if (minimum[x] == x){
        if (p != -1){
            swap(minimum[x], minimum[p]);
        }
        else swap(minimum[x], minimum[adjlist[x][0]]);
        min_counter += 2;
    }
}

void dfs_size(int x, int p){
    ss[x] = 1;
    // pp[x] = p;
    for (auto i: adjlist[x]){
        if (i == p) continue;
        pp[i] = x;
        dfs_size(i,x);
        ss[x] += ss[i];
    }
}

int get_centroid(int x, int p){
    for (auto i: adjlist[x]){
        if (i == p) continue;
        if (ss[i] * 2 > n){
            return get_centroid(i, x);
        }
    }

    return x;
}

void dfs_nodes(int x, int p){
    // hp[x] = p;
    for (auto i: adjlist[x]){
        if (i == p) continue;
        hp[i] = hp[x];
        dfs_nodes(i, x);
    }
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    // int n;
    cin>>n;
    // vector<int>adjlist[n+5];

    for (int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    //get the minimum
    // int minimum[n+5];
    for(int i=1; i<=n; i++){
        minimum[i] = i;
    }
    dfs(1, -1);
    dfs_size(1, -1);

    //get the maximum
    for (int i=2; i<=n; i++){
        max_counter += 2*min(ss[i], n-ss[i]);
    }

    int centroid = get_centroid(1, -1);
    // cout<<centroid<<'\n';
    hp[centroid] = centroid;
    for (auto i: adjlist[centroid]){
        hp[i] = i;
        dfs_nodes(i, centroid);
    }
    vector<int>trees[100010];
    for (int i=1; i<=n; i++){
        trees[hp[i]].push_back(i);
    }

    vector<vector<int>> v;
    for (auto i: adjlist[centroid]){
        v.push_back(trees[i]);
    }
    v.push_back(trees[centroid]);

    sort(v.begin(), v.end(), comp);

    queue<int>q;
    for (int i=1; i<v.size(); i++){
        for (auto i: v[i]){
            q.push(i);
        }
    }

    for (auto vect: v){
        for (auto i: vect){
            maximum[i] = q.front();
            q.pop();
            q.push(i);
        }
    } 
    for (int i=1; i<=n; i++){
        if (minimum[i] == i)return i;
    }
    cout<<min_counter<<' '<<max_counter<<'\n';
    for (int i=1; i<=n; i++){
        cout<<minimum[i]<<' ';
        // if (minimum[i] == i) return i;
    }
    cout<<'\n';
    for (int i=1; i<=n; i++){
        cout<<maximum[i]<<' ';
    }
    cout<<'\n';

    return 0;
}