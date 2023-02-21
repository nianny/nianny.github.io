#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int t;
    cin>>t;

    for (int i=0; i<t; i++){
        int n;
        cin>>n;
        int arr[n];
        int sum = 0;
        for (int x=0; x<n; x++){
            cin>>arr[x];
            sum += abs(arr[x]);
        }   

        int ans = 0;
        int pos = 0;
        while (sum > 0){
            if (arr[pos] == 0){
                pos++;
                continue;
            }
            bool greater = true; //what are we looking for
            if (arr[pos] > 0){
                greater = false;
                arr[pos] -=1;
                sum -= 1;
            }
            else{
                greater = true; 
                arr[pos] += 1;
                sum -= 1;
            } 

            for (int x=pos; x<n; x++){
                if (greater && arr[x] > 0){
                    arr[x]-= 1;
                    sum -=1;
                    greater = !greater;
                }
                else if (!greater && arr[x] < 0){
                    arr[x] += 1;
                    sum -= 1;
                    greater = !greater;
                }
            }

            ans++;
            cout<<ans<<' '<<sum<<'\n';
        }
        cout<<ans<<'\n';
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

