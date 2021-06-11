#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int s,e,a,b;
    cin>>s>>e>>a>>b;
    for (int i=s; i<=e; i++){
        if (i%a==0 && i%b==0){
            cout<<"FizzBuzz";
        }
        else if (i%a==0){
            cout<<"Fizz";
        }
        else if (i%b==0){
            cout<<"Buzz";
        }
        else{
            cout<<i;
        }
        cout<<'\n';
    }
    return 0;
}
