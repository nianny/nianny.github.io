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

    for (int m = 0; m<t; m++){
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++){
            cin>>arr[i];
        }
        bool flag = false;
        int a,b,c;
        for (b=0; b<n; b++){
            bool afound = false;
            bool bfound = false;
            for (a=b-1; a>=0; a--){
                if (arr[a] < arr[b]){
                    afound = true;
                    break;
                }
            }

            for (c=b+1; c<n; c++){
                if (arr[c] < arr[b]){
                    bfound = true;
                    break;
                }
            }
            if (afound && bfound){
                flag = true;
                cout<<"YES"<<endl;
                cout<<a+1<<' '<<b+1<<' '<<c+1<<endl;
                break;
            }
        }

        if (!flag){
            cout<<"NO"<<'\n';
        }
    }
    return 0;
}
