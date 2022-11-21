#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,q;
    cin>>n>>q;
    set<int> s;
    for (int i=0; i<q; i++){
        string a;
        cin>>a;
        if (a == "WAKE"){
            int b;
            cin>>b;
            s.erase(b);
        }
        else if (a == "SLEEP"){
            int b;
            cin>>b;
            s.insert(b);
        }
        else{
            int b,c;
            cin>>b>>c;
            auto value = s.lower_bound(b);
            if (value==s.end() || *value>c) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
    
    return 0;
}
