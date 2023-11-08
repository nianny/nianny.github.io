#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    int x=0;
    int y=0;

    for (int i=0; i<n; i++){
        string s;
        cin>>s;
        int k;
        cin>>k;

        if (s=="UP"){
            y+=k;
        }
        else if (s=="DOWN"){
            y-=k;
        }
        else if (s=="RIGHT"){
            x+=k;
        }
        else{
            x-=k;
        }
    }

    cout<<x<<' '<<y;


    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

