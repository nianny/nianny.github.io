#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,m;
    cin>>n>>m;
    int A[n];
    int T[n];
    for (int i=0; i<n; i++){
        cin>>T[i];
    }

    for (int i=0; i<n; i++){
        cin>>A[i];
    }
    
    for (int i=0; i<m; i++){
        int a;
        cin>>a;
        bool flag = true;
        for (int p=0; p<n; p++){
            if (T[p]>a){
                cout<<A[p-1]<<'\n';
                flag = false;
                break;
            }
        }

        if (flag){
            cout<<A[n-1]<<'\n';
        }

    }

    
    return 0;
}
