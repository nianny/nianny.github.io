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

    if (n>=91){
        cout<<"A*";
    }
    else if (n >= 75){
        cout<<"A";
    }
    else if (n >= 60){
        cout<<"B";
    }
    else if (n >= 50){
        cout<<"C";
    }
    else if (n >= 35){
        cout<<"D";
    }
    else if (n >= 20){
        cout<<"E";
    }
    else {
        cout<<"U";
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

