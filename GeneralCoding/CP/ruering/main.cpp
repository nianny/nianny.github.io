#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    for (int welp=0; welp<10; welp++){
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        for (int i=0; i<n; i++){
            // index is i+1
            int id, r;
            cin>>id>>r;
            int minimum;
            cin>>minimum;
            for (int p=1; p<r; p++){
                int a;
                cin>>a;
                minimum = min(minimum, a);
            }

            v.push_back(make_pair(minimum, id));
        }
        sort(v.begin(), v.end());
        int best = v[0].first;
        
        vector<int> ans;
        for (auto it: v){
            if (it.first == best){
                ans.push_back(it.second);
            }
        }
        sort(ans.begin(), ans.end());
        cout<<best<<" {";
        for (int i=0; i<ans.size(); i++){
            if (i!=0) cout<<",";
            cout<<ans[i];
        }
        cout<<"}\n";

    }
    
    
    return 0;
}
