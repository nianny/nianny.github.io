#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        int ans =0;
        for (int p=1; p<s.length(); p++){
            if (s[p] == 'J' && s[p-1] == 'C'){
                ans += x;
            }
            else if (s[p] == 'C' && s[p-1] == 'J'){
                ans += y;
            }
            else if (s[p] == '?' && s[p+1] == '?'){
                s[p] = s[p-1];
            }
            else if (s[p] == '?'){
                int a = 0; //is J
                int b = 0; //is C
                if (s[p-1] == 'C'){
                    a += x;
                }
                if (s[p+1] == 'C'){
                    a += y;
                }
                if (s[p-1] == 'J'){
                    b+= y;
                }
                if (s[p+1] == 'J'){
                    b+= x;
                }
                ans += min(a,b);
            }
            cout<<s[p]<<' '<<ans<<'\n';
        }
        cout<<"Case #"<<i+1<<": "<<ans<<'\n';
    }
    return 0;
}