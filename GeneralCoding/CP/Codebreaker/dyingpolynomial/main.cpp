#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int q;
    cin>>q;

    for (int i=0; i<q; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        int l=1;
        int r=100000;
        int mid;
        while (r > l){
            mid = l + (r-l)/2;
            if (a*mid*mid*mid+b*mid*mid+c*mid >= d){
                r = mid;
            }
            else{
                l=mid+1;
            }
        }

        cout<<l<<'\n';

    }
    
    return 0;
}
