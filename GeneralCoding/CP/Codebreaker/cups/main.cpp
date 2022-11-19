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
    
    multiset<int> m;
    int added = 0; 
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        
        if (a==1){
            if (m.find(b-added) != m.end()) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
        else if (a==2){
            m.insert(b-added);
        } else{
            added += b;
        }
    }
    
    return 0;
}
