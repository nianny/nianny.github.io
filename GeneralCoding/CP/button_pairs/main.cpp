#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n;
    cin>>n;

    int even = 0;
    int odd = 0;

    for (int i =0;i<n; i++){
        int a;
        cin>>a;
        if (a%2==0){
            even++;
        }
        else{
            odd++;
        }
    }

    cout<<even*odd;
    
    
    return 0;
}
