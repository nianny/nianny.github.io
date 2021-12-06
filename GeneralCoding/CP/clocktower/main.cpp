#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n,h;
    cin>>n>>h;
    int ratio = h/n;
    int count = 0;
    // cout<<ratio<<'\n';

    for (int i=1; i<n; i++){
      int height;
      cin>>height;

      // cout<<i<<'\t'<<height<<' '<<height/i<<'\n';
      if ((height/i) >= ratio){
        count ++;
      }
    }

    if (!count){
      cout<<"Yes";
    }
    else {
      cout<<"No"<<'\n'<<count<<'\n';
    }

    return 0;
}

/*
6 30
10 6 15 30 9
*/

/*
10 20
1 2 3 4 5 6 7 8 9
*/
