#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'

int divsum[1000005];
int val[1000005];


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int t;
    cin>>t;


    for (int i=1; i<=1000000; i++){
        for (int j=i; j<=1000000; j+=i){
            divsum[j] += i;
        }
    }

    for (int i=1; i<=1000000; i++){
        val[i] = max(val[i-1], divsum[i]);
    }

    for (int i=0; i<t; i++){
        int n;
        cin>>n;

        cout<<val[n]<<endl;
    }
    
    
    return 0;
}
