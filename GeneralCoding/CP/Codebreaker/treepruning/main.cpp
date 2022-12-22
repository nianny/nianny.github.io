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
        adjlist[b].push_back(a);
    }

    int count[n];
    int ans = n;
    bool ded[n];
    memset(ded, false, sizeof ded);
    for (int i=0; i<n; i++){
        count[i] = adjlist[i].size();
    }

    bool isnow = true;
    queue<int>now;
    queue<int>second;
    bool popped[n];
    memset(popped, false, sizeof popped);

    for (int i=0; i<n; i++){
        if (count[i] <= 1){
            now.push(i);
            popped[i] = true;
        }
    }
    

    while(k-- && now.size() + second.size() > 0){
        if (isnow){
            while(!now.empty()){
                int c = now.front(); now.pop();
                // cout<<c<<'\n';
                ans--;
                for (auto i: adjlist[c]){
                    if (popped[i]) continue;
                    count[i]--;
                    if (count[i] <= 1) {
                        popped[i] = true;
                        // ans--;
                        second.push(i);
                    }
                }
            }
            isnow = !isnow;
        }
        else{
            while(!second.empty()){
                int c = second.front(); second.pop();
                // cout<<c<<'\n';
                ans--;
                for (auto i: adjlist[c]){
                    if (popped[i]) continue;
                    count[i]--;
                    if (count[i] <= 1) {
                        popped[i] = true;
                        // ans--;
                        now.push(i);
                    }
                }
            }
            isnow = !isnow;
        }
    }
    // for (int i=0; i<n; i++){
    //     cout<<count[i]<<' ';
    // }
    // cout<<'\n';

    cout<<ans;
    
    
    return 0;
}
