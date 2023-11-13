#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int arr[100005];
int n,m;
bool checker (int x){
    int counter = 0;
    for (int i=0; i<m; i++){
        
        int sum = 0;
        while (counter<n && sum + arr[counter] <= x){
            // cout<<x<<' '<<i<<' '<<counter<<'\n';
            sum += arr[counter];
            counter++;
        }
        if (counter >= n){
            return false;
        }
        // cout<<x<<' '<<i<<' '<<counter<<'\n';
    }

    return true;
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    
    cin>>n>>m;
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }


    int low=0, high = 1000000000000000000;
    int mid;
    while (high - low > 1){
        mid = (low + high) / 2;

        if (checker(mid)){
            low = mid;
        }
        else {
            high = mid;
        }
    }

    // for (int i=0; i<30; i++){
    //     cout<<checker(i)<<' ';
    // }

    cout<<low<<' '<<high<<'\n';
    cout<<high;
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

