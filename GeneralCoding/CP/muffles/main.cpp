/*

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int t;
    cin>>t;
    for (int hi = 0; hi<t; hi++){
        int n,k;
        cin>>n>>k;
        vector<int> v;
        for (int i=0; i<n; i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        for (int a=1; a<=k; a++){
            for (int b=1; b<=k; b++){
                vector<int> indi = v;
                indi.push_back(a);
                indi.push_back(b);
                sort(indi.begin(), indi.end());
                int count = 0;
                for (int c=1; c<=k; c++){
                    if (indi.upper_bound(c))
                }
            }
        }
    }
    return 0;
}