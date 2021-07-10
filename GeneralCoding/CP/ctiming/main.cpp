#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi;
    int a,b,c;
    cin>>a>>b>>c;
    int day = a-11;
    int hour = b-11;
    int minute = c-11;

    int time = day * 60 * 24 + hour * 60 + minute;
    if (time < 0){
        cout<<-1;
    }
    else {
        cout<<time;
    }

    
    return 0;
}
