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
    unordered_map<string,bool> m;
    for (int i=0; i<n; i++){
        string a,b;
        cin>>a>>b;

        if (m[a+b]){
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<'\n';
            m[a+b] = 1;
        }
    }
    
    return 0;
}

