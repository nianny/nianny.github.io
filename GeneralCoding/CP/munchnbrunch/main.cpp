#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    for (int p=0; p<10; p++){
        int cost;
        cin>>cost;

        float y1,y2,y3,y4;
        cin>>y1>>y2>>y3>>y4;

        int n;
        cin>>n;

        int total = y1*n*12 + y2*n*10 + y3*n*7 + y4*n*5;
        if (total/2 > cost){
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
    }
    
    return 0;
}
