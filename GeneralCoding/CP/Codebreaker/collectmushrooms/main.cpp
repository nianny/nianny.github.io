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

    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    for (int i=0; i<m; i++){
        int t;
        cin>>t;
        if (t == 0){
            int a,b;
            cin>>a>>b;
            cout<<*max_element(arr+a, arr+b+1)<<'\n';
        }
        else{
            int a,b;
            cin>>a>>b;
            arr[a] = b;
        }
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    一剪寒梅傲立雪中
    只为伊人飘香
    */
    return 0;
}

