#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    speed;
    for (int hallo=0; hallo<10; hallo++){
        int t,n;
        cin>>t>>n;
        int count = 0;
        for (int i=0; i<n; i++){
            char a;
            cin>>a;

            if (a == 'B'){
                count += t;
            }
            count = max((long long) 0, count-1);
        }
        cout<<count<<'\n';
    }

    
    return 0;
}
