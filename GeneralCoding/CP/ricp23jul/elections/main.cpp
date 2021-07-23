#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);

int n;
vector<pair<int,int>> v;

int dp(int i, int w){
    if (i==0) return 0;
    if (w<=0) return 0;
    cout<<i<<' '<<w<<'\n'; // <<max(max(dp(i, w-1), dp(i-1, w)), dp(i-1, w-v[i].first) + v[i].second)<<' '<<'\n';
    return max(max(dp(i, w-1), dp(i-1, w)), dp(i-1, w-v[i].first) + v[i].second);
    // return max(dp(i, w-1), dp(i-1, w), dp(i-1, w-v[i].first) + v[i].second);
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    
    cin>>n;
    
    int sum = 0;
    for (int i=0; i<n; i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        sum += a;
        if ((c-b) < d){
            v.push_back(make_pair(a, c-b));
        }
    }

    if (v.empty()){
        cout<<"impossible"<<'\n';
        return 0;
    }    

    cout<<dp(n-1, (sum/2)+1);


    
    return 0;
}
