#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int holes[2000005];

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,h;
    cin>>n>>h;
    multiset<int>s;
    for (int i=0; i<h; i++){
        s.insert(0);
    }
    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        if (a==1){
            int p;
            cin>>p;
            s.erase(s.find(holes[p%h]));
            holes[p%h]+=1;
            s.insert(holes[p%h]);
        }
        else{
            int p;
            cin>>p;
            s.erase(s.find(holes[p%h]));
            holes[p%h]-=1;
            s.insert(holes[p%h]);
        }
        cout<<*(--s.end())<<'\n';
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

