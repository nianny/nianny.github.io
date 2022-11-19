#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,q;
    cin>>n>>q;
    set<int> s;
    int ss[n+5];

    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        s.insert(a);

        ss[i] = s.size();  
    }

    for (int i=0; i<q; i++){
        int l;
        cin>>l;

        cout<<ss[l-1]<<' ';
    }

    


    
    
    return 0;
}
