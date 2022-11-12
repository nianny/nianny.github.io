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
    map<int, map<int, bool> > m;
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;

        if (m[a].find(b) == m[a].end()){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
        m[a][b] = true;
    }
    
    return 0;
}
