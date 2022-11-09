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
    for (int ha=0; ha<t; ha++){
        int n;
        cin>>n;

        deque<int> v;
        for (int i=1; i<=n; i++){
            v.push_back(i);
        }
        int value;
        if (n%2==0){
            value = n/2;
        }
        else{
            value = n/2+1;
        }
        cout<<value<<'\n';
        while (v.size() > 1){
            cout<<v.front()<<' '<<v.back()<<'\n';
            v.pop_front();
            v.pop_back();
        }


        for (int i=0; i<n-(n/2)-1; i++){
            cout<<value<<' '<<value<<'\n';
        }
    }
    
    return 0;
}
