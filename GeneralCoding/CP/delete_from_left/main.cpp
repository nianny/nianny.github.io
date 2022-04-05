#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    string s,t;
    cin>>s>>t;


    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    int minSize = min(s.size(), t.size());
    cout<<minSize<<endl;
    cout<<s.size()<<' '<<t.size()<<endl;

    for (int i=0; i<minSize; i++){
        if (s[i] != t[i]){
            cout<<(s.size()+t.size()-2*i)<<endl;
            return 0;
        }
    }
    cout<<(s.size()+t.size())-2*minSize<<endl;
    
    
    return 0;
}
