#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    string s;
    int k;
    cin>>s>>k;
    unordered_set<string>v;
    for (int i=0; i<s.length(); i++){
        string a;
        for (int p=i; p<min((int)i+k,(int)s.length()); p++){
            a+=s[p];
            v.insert(a);
        }
    }
    vector<string> vec;
    for (auto i: v){
        vec.push_back(i);
    }
    sort(vec.begin(), vec.end());

    // cout<<'\n';a
    cout<<vec[k-1];
    
    return 0;
}
