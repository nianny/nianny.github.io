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
    for (int m=0; m<t; m++){
        int n;
        cin>>n;

        int q = 0;
        // int a = 0;

        for (int i=0; i<n; i++){
            char haallo;
            cin>>haallo;
            if (haallo == 'Q'){
                q ++;
            }
            else{
                if (q > 0){
                    q --;
                }
            }
        }

        if (q > 0){
            cout<<"No"<<'\n';
        }
        else{
            cout<<"Yes"<<'\n';
        }
    }
    
    return 0;
}
