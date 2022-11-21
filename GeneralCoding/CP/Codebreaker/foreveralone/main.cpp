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
    set<int> s;
    for (int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;

        if (a==b) continue;
        else{
            s.insert(a); s.insert(b);
        }
    }
    cout<<n-s.size();
    
    return 0;
}
