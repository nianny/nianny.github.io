#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int arr[100010];
struct node{
    int s,e,m;
    int val[60];
    node *l, *r;
    
    node(int _s, int _e){
        s = _s, e=_e, m=s+e>>1;
        for (int i=0; i<60; i++){
            val[i] = 0;
        }

        if (s != e){
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }

    void merge(){
        for (int i=0; i<60; i++){
            int left_time = l->val[i];
            // if((left_time + i) % arr[m] == 0){
            //     left_time += 2;
            // }
            // else left_time += 1;
            val[i] = left_time + r->val[(i+left_time)%60];
        }
    }

    void update(int x, int v){
        if (s == e) {
            for (int i=0; i<60; i++){
                if (i % v == 0){
                    val[i] = 2;
                }
                else{
                    val[i] = 1;
                }
            }
        }
        else{
            if (x <= m) l->update(x,v);
            else r->update(x,v);

            merge();
        }
    }

    int query(int _s, int _e, int t){
        if (s == _s && e == _e) return val[t];
        else{
            if (_e <= m) return l->query(_s, _e, t);
            else if (m < _s) return r->query(_s, _e, t);

            else{
                // return 0;
                int dura = l->query(_s, m, t);
                // if ((dura+t) % arr[m] == 0){
                //     dura += 2;
                // }
                // else{
                //     dura ++;
                // }
                // return 0;

                dura += r->query(m+1, _e, (dura + t) % 60);
                // return 0;
                return dura;
            }
        }
    }
}*root = new node(0, 100005);

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    for (int i=0; i<100010; i++){
        arr[i] = 1e9;
    }
    
    int n,q;
    cin>>n>>q;
    // return 0;

    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        arr[i] = a;
        root->update(i,a);
    }
    // return 0;

    for (int i=0; i<q; i++){
        int pol;
        cin>>pol;

        if (pol == 0){
            int l,r;
            cin>>l>>r;
            // cerr<<l<<' '<<r<<'\n';
            // return 0;
            if (l == r) cout<<0<<'\n';
            else cout<<root->query(l, r-1, 0)<<'\n';
        }
        else{
            int x, p;
            cin>>x>>p;
            arr[x] = p;
            root->update(x, p);
        }
    }
    // for (int i=0; i<n; i++){
    //     cout<<arr[i]<<' ';
    // }
    // cout<<'\n';

    // for (int i=0; i<n; i++){
    //     cout<<root->query(i,i,4)<<' ';
    // }
    // cout<<'\n';

    // cout<<root->query(0, 1, 0);

    
    
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

