#include <bits/stdc++.h>
using namespace std;
#define int long long
#define beegspeed ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pi pair<int,int>

vector<pi> sd;
// int ans;

int shade(int x,int y){
    int answ,cur = 1e7;
    for(auto it:sd){
        cur = max(abs(x - it.first), abs(y - it.second));
        answ  = min(answ, cur);
    }
    return answ;
}

int32_t main(){
    int ans = 0;
    beegspeed;
    int n,x,y; cin>>x>>y>>n;
    for(int i = 0;i<n;i++){
        int sdx,sdy; cin>>sdx>>sdy;
        --sdx; --sdy;
        sd.push_back(mp(sdx,sdy));
    }
    for(int i = 0;i<x;i++){
        for(int j = 0; j<y; j++){
            // cout<<i<<' '<<j<<':'<<ans<<' '<<shade(i,j)<<' ';
            // shade(i,j);
            ans = max(ans,shade(i,j));
            // int hallo = ans;
            // cout<<hallo<<'\n';
            // cout<<ans<<'\n';

            cout<<"";
        }
        // cout<<ans<<'\n';
    }
    // cout<<ans<<'\n';
    cout<<"Final Answer:"<<ans+1;
}