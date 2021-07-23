#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n;
    cin>>n;
    int arr[n];
    int num = 0;
    for (int i=0; i<n; i++){
        cin>>arr[i];
        num = max(num, arr[i]);
    }
    int ans = 0;
    int times = 0;
    for (int i=2; i<=num; i++){
        int time = 0;
        for (int j=0; j<n; j++){
            if (arr[j]%i == 0){
                time++;
            }
        }
        if (time > times){
            times = time;
            ans = i;
        }
    }

    cout<<ans;

    
    return 0;
}