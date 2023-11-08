#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,a,b;
    cin>>n>>a>>b;

    for (int i=1; i<=n; i++){
        if (i%a==0 && i%b==0){
            cout<<"FizzBuzz"<<endl;
        }
        else if (i%a==0){
            cout<<"Fizz"<<endl;
        }
        else if (i%b==0){
            cout<<"Buzz"<<endl;
        }
        else{
            cout<<i<<endl;
        }
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

