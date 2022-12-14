#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int pre[500010];
int post[500010];
vector<int> adjlist[500010];
// int par[500010];

int fen[500010];
// int arr[500010];
int counter = 1;
int n;
void dfs(int x, int p){
    pre[x] = counter++;
    // par[x] = p;
    for (auto i: adjlist[x]){
        if (i != p) dfs(i, x);
    }
    post[x] = counter-1;
}

void fen_update(int x, int v){
    while (x <=n){
        fen[x] += v;
        x += x&-x;
    }
}

int fen_query(int r){
    int result = 0;
    while(r){
        result += fen[r];
        r -= r&-r;
    }

    return result;
}


struct node{
    int s,m,e;
    int lazy;
    pair<int,int>val;
    node *l = nullptr, *r=nullptr;

    node(int S, int E){
        s=S; e=E;
        m = (s+e)/2;
        lazy = 0;
        val = {0,0};

        if (s == e){
            val.second = s;
        }
        else{
            l = new node(s,m);
            r = new node(m+1, e);
        }
    }

    // void create(){
    //     if (s != e){
    //         l = new node(s,m);
    //         r = new node(m+1, e);
    //     }
    // }

    void propagate(){
        if (lazy == 0) return;

        val.first += lazy;
        // if (l == nullptr) create();

        if (s != e){
            l->lazy += lazy;
            r->lazy += lazy;
        }
        lazy = 0;
    }

    void update(int S, int E, int V){
        // if (l==nullptr) create();
        if (s == S && e == E) lazy += V;
        else{
            if (E<=m) l->update(S,E,V);
            else if (m < S) r->update(S,E,V);
            else l->update(S,m,V), r->update(m+1, E,V);

            l->propagate(); r->propagate();

            if (l->val.first > r->val.first){
                val = l->val;
            }
            else{
                val = r->val;
            }
        }
    }

    // pair<int,int> query(int S, int E){
    //     if (l==nullptr) create();
    //     propagate();

    //     if (s==S && e == E) return val;
    //     else if (E <=m) return l->query(S,E);
    //     else if (m < S) return r->query(S,E);
    //     else{
    //         if (l->query(S,m).first > r->query(m+1,E).first){
    //             return l->query(S,m);
    //         }
    //         else{
    //             return r->query(m+1,E);
    //         }
    //     }
    // }

    pair<int,int> query(){
        propagate();
        return val;
    }
}*root; // 5000010

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    
    // int n,x;
    int x;
    cin>>n>>x;
    root = new node(0, n);
    vector<pair<int,int>>v;
    for (int i=1; i<=n; i++){
        int a;
        cin>>a;
        v.push_back({a, i});
    }

    for (int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    dfs(1, -1);
    // for (int i=1; i<=n; i++){
    //     cout<<i<<' '<<pre[i]<<' '<<post[i]<<'\n';
    // }

    for (auto [j,i]: v){
        // cout<<"SETTING "<<i<<' '<<pre[i]<<' '<<j<<'\n';
        root ->update(pre[i], pre[i], j);
    }

    // for (int i=0; i<=n; i++){
    //     cout<<i<<' '<<root->query(i,i).first<<' '<<root->query(i,i).second<<'\n';
    // }
    int q;
    cin>>q;

    for (int i=0; i<q; i++){
        int t;
        cin>>t;
        pair<int,int> q = root->query();
        while (q.first >= x){
            // cout<<root->query().first<<' '<<root->query().second<<'\n';
            fen_update(q.second, 1);
            // arr[root->query().second] = 1;
            // for (int i=0; i<n; i++){
            //     cout<<fen[i]<<' ';
            // }
            // cout<<'\n';
            root->update(q.second, q.second, LLONG_MIN);
            q = root->query();
        }

        if (t == 1){
            int s,c;
            cin>>s>>c;
            // cout<<"ADDD "<<c<<" TO "<<pre[s]<<' '<<post[s]<<'\n';
            root->update(pre[s], post[s], c);
        }
        else{
            int y;

            cin>>y;
            // y--;
            // cout<<"Y "<<y<<'\n';
            // for (int i=0; i<=n; i++){
            //     cout<<i<<' '<<root->query(i,i).first<<' '<<root->query(i,i).second<<'\n';
            // }
            // pair<int,int> hai = root->query();

            // cout<<"HAI "<<hai.first<<' '<<hai.second<<'\n';
            // for (int i=0; i<n; i++){
            //     cout<<fen[i]<<' ';
            // }
            
            // for (int i=0; i<n; i++){
            //     cout<<arr[i]<<' ';
            // }
            // cout<<'\n';
            int in;
            if (pre[y] == 0){
                in = fen_query(post[y]);
            }
            else{
                in = fen_query(post[y])-fen_query(pre[y]-1);
            }
            int out = fen_query(n) - in;
            // cout<<in<<' '<<out<<'\n';

            cout<<in*out<<'\n';
        }
    }

    // for (int i=0; i<n; i++){
    //     cout<<fen[i]<<' ';
    // }
    return 0;
}
