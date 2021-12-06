#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n,a,b;
    cin>>n>>a>>b;



    for (int i=1; i<=n; i++){
        if (i % a == 0 || i % b == 0){
            if (i % a == 0){
                cout<<"Fizz";
            }
            if (i % b == 0){
                cout<<"Buzz";
            }
        }
        else {
            cout<<i;
        }

        cout<<'\n';
    }


    return 0;
}
