#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int t;
    cin>>t;

    for (int x=0; x<t; x++){
        int n;
        cin>>n;
        int ans = 0;
        set<int>s;
        for (int i=1; i<=n; i++){
            s.insert(i);
        }

        
        vector<int>pos;
        for (int i=1; i<=n; i++){
            int a;
            cin>>a;

            if (a == -1) pos.push_back(i);
            else{
                ans += max((int)0, a-i);
                ans %= 998244353;
                s.erase(a);
                // cout<<a<<' '<<i<<' '<<ans<<'\n';
            }
        }
        int multiplier = 1;
        for(int i=1; i<s.size(); i++){
            multiplier *= i;
            multiplier %= 998244353;
        }

        ans *= max((int)1, (int)multiplier*(int)s.size())%998244353;
        ans %=998244353;
        // cout<<ans<<' '<<multiplier<<'\n';

        for (auto ele:s){
            for (auto i:pos){
                ans += max((int)0, ele-i)*multiplier;
                // cout<<ele<<' '<<i<<' '<<ans<<'\n';
                ans %= 998244353;
            }
        }
        cout<<ans<<'\n';


    }
    
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    一剪寒梅傲立雪中
    只为伊人飘香
    */
    return 0;
}

