#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int t;
    cin>>t;

    for (int i=0; i<t; i++){

        deque<int>dq;
        int arr[4];
        for (int x=0; x<4; x++){
            cin>>arr[x];
        }
        // for (int x=0; x<4; x++){
        //     cout<<arr[i]<<'\t';
        // }
        // cout<<'\n';
        dq.push_back(arr[0]);
        dq.push_back(arr[1]);
        dq.push_back(arr[3]);
        dq.push_back(arr[2]);
        bool flag = false;
        for (int x=0; x<4; x++){
            // for (auto y:dq){
            //     cout<<y<<' ';
            // }
            // cout<<'\n';
            if (dq[0] < dq[1] && dq[0] < dq[3] && dq[1] < dq[2] && dq[3] <dq[2]){
                flag = true;
            }

            dq.push_front(dq.back());
            dq.pop_back();
        }

        if (flag){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
    }
    
    
    return 0;
}
