#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#pragma GCC optimize(O3);

int n,q;
int A[2010];
int B[2010];

int query(){
    for (int i=1; i<=n; i++){
        int asum = 0;
        int bsum = 0;

        for (int x=1; x<=n; x++){
            asum += abs(A[i]-A[x]);
        }
        for (int x=1; x<=n; x++){
            bsum += abs(A[i]-B[x]);
        }

        // cout<<i<<' '<<asum<<' '<<bsum<<'\n';

        if (bsum >= asum){
            return i;
        }
    }

    return -1;
}

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