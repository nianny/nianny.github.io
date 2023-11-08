#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int t;
    cin>>t;

    for (int tc=0; tc<t; tc++){
        int n;
        cin>>n;
        bool found = false;
        for (int i=0; i<=n; i+=111){
            if ((n-i)%11==0){
                found = true;
                break;
            }
        }
        cout<<((found)?"YES":"NO")<<endl;
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

