#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

struct node{
    int s,e,m;
    pair<int,int> val;

    node *l, *r;

    node(int _s, int _e){
        s = _s, e = _e, m = s+e>>1;
        val = {0,0};

        if (s == e){
            val.second = s;
        }
        else {
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }


    void update(int X, int V){
        if (s == e) val.first = V;
        else{
            if (X <= m) l->update(X,V);
            else if (X>m) r->update(X,V);


            if (l->val.first >= r->val.first){
                val = l->val;
            }
            else{
                val = r->val;
            }
        }
    }

    pair<int,int> query(int S, int E){
        if (s == S && e == E) return val;
        else{
            if (E<=m) return l->query(S,E);
            else if (m<S) return r->query(S,E);
            else{
                pair<int,int> left = l->query(S,m);
                pair<int,int> right = r->query(m+1, E);

                if (left.first >= right.first){
                    return left;
                }
                else{
                    return right;
                }
            }
        }
    }

}*root = new node(0, 200005);
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,m;
    cin>>n>>m;


    for (int i=0; i<n; i++){
        int a;
        cin>>a;

        root->update(i,a);
    }

    for (int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;

        pair<int,int> largest = root->query(a,b);
        cout<<largest.first<<'\n';

        root->update(largest.second, -1);

        for (int i=0; i<n; i++){
            cout<<root->query(i,i).first<<' ';
        }
        cout<<'\n';
    }


    
    return 0;
}
