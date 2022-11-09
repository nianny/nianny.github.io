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
    for (int m = 0; m<t; m++){
        int n;
        cin>>n;
        set<char>s;
        int score = 0;
        for (int i=0; i<n; i++){
            char a;
            cin>>a;
            s.insert(a);
            score++;
        }
        score += s.size();
        cout<<score<<'\n';
    }
    return 0;
}
