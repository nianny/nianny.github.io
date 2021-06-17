#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi
    int n,ma;
    cin>>n>>ma;
    map<int,int>m;
    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        m[a]++;
    }
    int ans=0;
    for(auto it:m){
        if ((it.second > ans)&&it.second<=ma){
            ans = it.second;
        }
    }
    cout<<ans;

    
    
    return 0;
}
