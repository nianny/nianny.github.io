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

    deque<char>dq;
    for (int i=0; i<n; i++){
        string s;
        cin>>s;

        if (s=="ADD_BACK"){
            char a;
            cin>>a;
            dq.push_back(a);
        }
        else if (s=="ADD_FRONT"){
            char a;
            cin>>a;
            dq.push_front(a);
        }
        else if (s=="SNIP_FRONT"){
            int x;
            cin>>x;
            for (int i=0; i<=x; i++){
                dq.pop_front();
            }
        }
        else if (s=="SNIP_BACK"){
            int x;
            cin>>x;
            for (int i=dq.size()-1; i>x; i--){
                dq.pop_back();
            }
        }
        else{
            int x;
            cin>>x;
            cout<<dq[x]<<endl;
        }
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

