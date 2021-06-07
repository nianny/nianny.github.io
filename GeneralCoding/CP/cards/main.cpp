#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int m,k;
    cin>>m>>k;
    deque<int>d;
    for (int i=0; i<m; i++){
        d.push_back(i);
    }
    while (true){
        char a;
        cin>>a;
        if (a == '.'){
            break;
        }
        if (a=='A'){
            d.push_back(d[0]);
            d.pop_front();
        }
        else if (a=='B'){
            int store = d[0];
            d.pop_front();
            d.push_back(d[0]);
            d.pop_front();
            d.push_front(store);
        }
    }

    cout<<d[k-1]<<' '<<d[k]<<' '<<d[k+1];
    return 0;
}