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
    
    vector<int>v;   
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        if (a==1){
            bool flag = false;
            for (auto p: v){
                if (p == b){
                    flag = true;
                }
            }

            if (flag) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }

        else if(a==2){
            v.push_back(b);
        }
        else {
            for (int p=0; p<v.size(); p++){
                v[p]+=b;
            }
        }
    }
    
    return 0;
}
