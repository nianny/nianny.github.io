#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    double position = (double)((double)((double)(bx-ax)*(double)(1-(double)(by/(double)(by+ay))))+ax);
    // cout<<(double)(bx-ax)*(double)(1-(double)(by/(double)(by+ay)))<<'\n';
    cout.precision(20);
    cout<<position;
    
    
    return 0;
}
