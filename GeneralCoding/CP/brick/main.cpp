#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    stack<int>s;
    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        if (s.empty()){
            s.push(a);
        }
        else{
            while (!s.empty() && s.top() <= a){
                s.pop();
            }
            s.push(a);
        }
    }
    while (!s.empty()){
        cout<<s.top()<<'\n';
        s.pop();
    }
    return 0;
}
