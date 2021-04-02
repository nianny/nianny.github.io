#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    bool arr [n+5];
    memset(arr,false,sizeof arr);
    vector<pair<int,int>>v;
    for (int i=1; i<=n; i++){
        int a;
        cin>>a;
        v.push_back(make_pair(a,i));
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int indi = 0;
    while (!v.empty()){
        pair<int,int> c = v.back();
        
        // v.pop_back();
        while(!v.empty() && v.back().first == c.first){
            pair<int,int>b = v.back();
            arr[b.second] = true;
            v.pop_back();
            int dcount = arr[b.second-1] + arr[b.second + 1];
            // cout<<dcount<<'\n';
            if (dcount == 2){
                indi --;
            }
            if (dcount == 0){
                indi ++;
            }
        }
        ans = max(ans,indi);
    
        // while (v!.empty() && )
    }
    cout<<ans;
    return 0;
}