#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int a,n;
    cin>>a>>n;

    stack<int>q;

    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        if (x==1){
            int a;
            cin>>a;
            q.push(a);
        }
        else{
            q.pop();
        }
    }

    int m = 0;
    while (!q.empty()){
        int val = q.top();
        q.pop();
        m = max(m, val);
    }

    cout<<m;
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

