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
    vector<int> v = {1,2,3,4,5,6,7};
    do{
        for(auto itr: v) cout<<itr<<' ';
        cout<<'\n';
    } while(next_permutation(v.begin(), v.end()));
    
    return 0;
}
