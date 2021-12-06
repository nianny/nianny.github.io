#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n,x;
    cin>>n>>x;
    int time = 1;


    while (n != 1 && time < x){
        if (n%2==0){
            n = n/2;
        }
        else{
            n = n*3+1;
        }
        time++;
    }

    if (time < x){
        cout<<-1;
    }
    else {
        cout<<n;
    }
    
    
    return 0;
}
