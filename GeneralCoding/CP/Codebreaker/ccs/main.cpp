#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,q;
    cin>>n>>q;

    set<int>s;

    for (int i=0; i<q; i++){
        string com;
        cin>>com;

        if (com=="WAKE"){
            int x;
            cin>>x;
            s.erase(x);
        }
        else if (com=="SLEEP"){
            int x;
            cin>>x;
            s.insert(x);
        }
        else{
            int a,b;
            cin>>a>>b;
            (s.lower_bound(a) != s.end() && *s.lower_bound(a) <= b) ? cout<<"NO"<<'\n' : cout<<"YES"<<'\n';

        }
    }
    
    return 0;
    
}

