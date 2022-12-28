#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);

int n,q;
int A[20010];
int B[20010];

//point update, range max query
struct node{
    int s,e,m;
    pair<int,int> val;
    int lazy;
    node *l, *r;

    node(int S, int E){
        s=S, e=E, m=s+e>>1;
        val = {0,0};
        lazy = 0;

        if (s != e){
            l = new node(s, m);
            r = new node(m+1, e);
        }
        else{
            val.second = s;
        }
    }

    void update(int X, int V){
        if (s == e) val.first += V;
        else{
            if (X <= m) l->update(X,V);
            else if (m < X) r->update(X,V);

            if (l->val.first >= r->val.first){
                val = l->val;
            }
            else{
                val = r->val;
            }
        }
    }

    pair<int,int> query(){
        // if (s == S && e == E) return val;
        // else{
        //     if (m >= E) l->query(S,E);
        //     else if (m < S) r->query(S,E);
        //     else{
        //         if (l->query(S, m) >= r->query(m+1, E)){
        //             return l->query(S,m);
        //         }
        //         else{
        //             return r->query(m+1, E);
        //         }
        //     }
        // }
        return val;
    }
}*root = new node(0, 200010);
// int query(){
//     for (int i=1; i<=n; i++){
//         int asum = 0;
//         int bsum = 0;

//         for (int x=1; x<=n; x++){
//             asum += abs(A[i]-A[x]);
//         }
//         for (int x=1; x<=n; x++){
//             bsum += abs(A[i]-B[x]);
//         }

//         // cout<<i<<' '<<asum<<' '<<bsum<<'\n';

//         if (bsum >= asum){
//             return i;
//         }
//     }

//     return -1;
// }

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    cin>>n>>q;
    for (int i=1; i<=n; i++){
        cin>>A[i];
    }

    for (int i=1; i<=n; i++){
        cin>>B[i];
    }
    // for (int i=1; i<=n; i++){
    //     cout<<B[i]<<' ';
    // }
    // cout<<'\n'<<'\n';
    // for (int i=1; i<=n; i++){
    //     cout<<abs(A[1]-B[i])<<' ';
    // }
    // cout<<'\n'<<'\n';

    cout<<query()<<'\n';

    for (int i=0; i<q; i++){
        int a,b,c;
        cin>>a>>b>>c;

        if (a == 1){
            A[b] = c;
        }
        else{
            B[b] = c;
        }

        cout<<query()<<'\n';
    }


    
    return 0;
}