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

    deque<int>dq;
    int val = 0;

    pair<string, int> arr[n];
    for (int i=0; i<n; i++){
        string s;
        cin>>s;

        if (s=="PUSH" || s=="IFZERO"){
            int x;
            cin>>x;
            arr[i] = {s, x};
        }
        else{
            arr[i] = {s, 0};
        }
    }
    for (int i=0; i<n; i++){
        string s = arr[i].first;
        int x = arr[i].second;

        if (s=="PUSH"){
            dq.push_back(x);
        }
        else if (s=="STORE"){
            val = dq.back();
            dq.pop_back();
        }
        else if (s=="LOAD"){
            dq.push_back(val);
        }
        else if (s=="PLUS"){
            int ans = dq.back();
            dq.pop_back();
            ans += dq.back();
            dq.pop_back();
            dq.push_back(ans);
        }
        else if (s=="TIMES"){
            int ans = dq.back();
            dq.pop_back();
            ans *= dq.back();
            dq.pop_back();
            dq.push_back(ans);
        }
        else if (s=="IFZERO"){
            if (dq.back() == 0){
                i = x-1;
            }
            dq.pop_back();
        }
        else{
            cout<<dq.back();
            return 0;
        }
    }
    
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

