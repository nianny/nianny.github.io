#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int s,e;
    cin>>s>>e;
    for (int i=s; i<=e; i++){
        string a = to_string(i);
        string b = a;
        reverse(b.begin(), b.end());
        if (a == b) cout<<"Palindrome!"<<'\n';
        else cout<<a<<'\n';

    }
    
    return 0;
}
