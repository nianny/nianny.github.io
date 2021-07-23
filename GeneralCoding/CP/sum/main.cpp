#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n;
    int sum = 0;
    cin >> n;
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        sum+=(a-1)*(b-a+1);
        sum+=(b-a+2)*(b-a+1)/2;
    }
    cout<<sum;
    
    return 0;
}
