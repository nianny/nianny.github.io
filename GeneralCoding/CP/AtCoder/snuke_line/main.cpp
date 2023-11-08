#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
struct node{
    int s,e,m;
    int val;
    node *l, *r;
    node(int S, int E){
        s = S, e = E, m=(s+e)/2;
        val = 0;

        if (s != e){
            l = new node(s,m);
            r = new node(m+1,e);
        }
    }

    void update(int X, int V){
        if (s == e){
            val += V;
            return;
        }
        if (X <= m) l->update(X,V);
        else r->update(X,V);
        val = l->val + r->val;
    }

    int query(int S, int E){
        if (s == E && e == E) return val;
        else if (E <= m) return l->query(S,E);
        else if (S > m) return r->query(S,E);
        else return l->query(S,m) + r->query(m+1,E);
    }


}*root;
//https://atcoder.jp/contests/arc068/tasks/arc068_c
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,m;
    cin>>n>>m;
    root = new node(0, m+5);

    deque<pair<int,pair<int,int>>> v;
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({b-a+1, {a,b}});
    }

    sort(v.begin(), v.end());
    for (int i=1; i<=m; i++){
        while(v.front().first == i){
            root->update(v.front().second.first, 1);
            root->update(v.front().second.second+1, -1);
            v.pop_front();
        }

        int ans = v.size();
        int sum = 0;
        for (int j=0; j<=m+1; j+=i){
            sum += root->query(max((int)0, j-i+1),j);
            ans += sum;
        }
        cout<<ans<<'\n';
    }

    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

