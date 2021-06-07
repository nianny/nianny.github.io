#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n,m;
    cin>>n>>m;
    int num = 0;
    for (int i=0; i<m; i++){
        
        string a;
        cin>>a;
        if (a=="LAND"){
            num++;
        }
        else if (a=="LEAVE"){
            num--;
        }
        else if (a=="EVACUATE"){
            num = 0;
        }
        if (num>n){
            cout<<"PLAN REJECTED";
            return 0;
        }
    }
    cout<<"PLAN ACCEPTED";
    return 0;
}