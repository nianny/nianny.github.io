#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;

    for (int i=1; i<=n; i++){
        for (int j=0; j<n-i; j++){
            cout<<' ';
        }
        for (int j=0; j<2*i-1; j++){
            cout<<'*';
        }
        cout<<'\n';
    }

    for (int i=n-1; i>=1; i--){
        for (int j=0; j<n-i; j++){
            cout<<' ';
        }
        for (int j=0; j<2*i-1; j++){
            cout<<'*';
        }
        cout<<'\n';
    }
    
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

