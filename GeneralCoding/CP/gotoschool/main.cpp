#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n;
    cin>>n;
    vector<pair<int,int>> p;

    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        p.push_back(make_pair(x, i+1));
    }

    sort(p.begin(), p.end());
    for (int i=0; i<n; i++){
        cout<<p[i].second<<" ";
    }
    
    
    return 0;
}
