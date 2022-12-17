#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,k;
    cin>>n>>k;

    vector<int>adjlist[n];
    for (int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;

        adjlist[a].push_back(b);
    }

    int count[n];
    int ans = 0;
    bool ded[n];
    memset(ded, false, sizeof ded);
    for (int i=0; i<n; i++){
        count[i] = adjlist[i].size();
        if (count[i] > 0){
            ans++;
        }
    }

    bool isnow = true;
    queue<int>now;
    queue<int>second;

    for (int i=0; i<n; i++){
        if (count[i] <= 1){
            now.push(i);
        }
    }
    
    
    return 0;
}
