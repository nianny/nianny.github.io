#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi;
    int t;
    cin>>t;
    int arr[t];
    for (int i=0; i<t; i++){
        int x1,y1, x2, y2, x3, y3;
        
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        int ans = abs(x1-x2) + abs(y2-y1);
        if ((x3==x1 && x3==x2 && y3 >min(y1, y2) && y3 < max(y1, y2)) || (y3==y1 && y3==y2 && x3>min(x1,x2) && x3 < max(x1,x2))){
            ans += 2;
        }
        arr[i] = ans;
    }
    for (int i=0; i<t; i++){
        cout<<arr[i]<<'\n';
    }

    
    return 0;
}
