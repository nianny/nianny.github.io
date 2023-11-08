#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int m,k;
    cin>>m>>k;
    deque<int> dq;
    for (int i=0; i<m; i++){
        dq.push_back(i);
    }
    char a;
    cin>>a;
    for (; a!='.'; cin>>a){
        

        if (a=='A'){
            int a = dq.front();
            dq.pop_front();
            dq.push_back(a);
        }
        else {
            int a = dq.front();
            dq.pop_front();
            int b = dq.front();
            dq.pop_front();
            dq.push_front(a);
            dq.push_back(b);
        }
    }
    
    cout<<dq[k-1]<<' '<<dq[k]<<' '<<dq[k+1]<<endl;
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

