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

    for (int hm =0; hm<t; hm++){
        string hmmm;
        cin>>hmmm;

        int pos = 0;
        string a = "";
        string b = "";
        while (hmmm[pos] != '+'){
            a += hmmm[pos];
            pos++;
        }
        pos++;
        for (int i=pos; i<hmmm.length(); i++){
            b += hmmm[i];
        }
        
        int a_i = stoll(a);
        int b_i = stoll(b);

        cout<<a_i+b_i<<'\n';
    }
    
    
    return 0;
}
