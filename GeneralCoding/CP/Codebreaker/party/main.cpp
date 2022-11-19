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
    int m;
    cin>>m;

    set<int> fwen;
    set<int> fwenoffwen;
    vector<int> adj[n+5];
    for (int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        if (a == 1) fwen.insert(b);
        if (b == 1) fwen.insert(a);
    }
    

    for (auto i: fwen){
        for (auto j: adj[i]){
            fwenoffwen.insert(j);
        }
    }

    fwenoffwen.insert(fwen.begin(), fwen.end());

    if (fwenoffwen.size() >= 1){
        cout<<fwenoffwen.size()-1;
    }
    else{
        cout<< 0;
    }
    
    return 0;
}
