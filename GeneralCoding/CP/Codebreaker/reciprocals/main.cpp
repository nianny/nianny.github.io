    #include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,m;
    cin>>n>>m;
    if (n%m==0){
        //cout m n/m
        for (int i=0; i<n; i++){
            cout<<n/m<<' ';
        }
    }
    else{
        //cout m-1 1
        for (int i=0; i<m-1; i++){
            cout<<1<<' ';
        }

        //n-(m-1) "slots" for 1
        for (int i=0; i<n-m+1; i++){
            cout<<n-m+1<<' ';
        }
    }
    
    
    return 0;
}
