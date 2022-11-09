#include <bits/stdc++.h>
using namespace std;
#define beegspeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int solve(vector<int> q){
    int mi = q[q.size() - 1];
    int ans = 0;
    for(int j = q.size() - 2; j>=0; j--){
        if(mi > q[j]) ans++;
        else{
            mi = q[j];
        }
    }
    return ans;
}
vector<int> ans;
int main(){
    //beegspeed
    int t; cin>>t;
    for(int i = 0; i < t; i++){
        cout<<i<<'\n';
        int c; cin>>c;
        vector<int> q(c);
        for(int j = 0; j < c; j++){
            cin>>q[j];
        }
        ans.push_back(solve(q));
    }
    for(auto it:ans) cout<<it<<'\n';
}