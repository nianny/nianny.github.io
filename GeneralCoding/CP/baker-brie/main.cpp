#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


int32_t main() {
    for (int hallo = 0; hallo<10; hallo++){
        int f,d;
        cin>>f>>d;
        int arr[d+5][f+5];
        int ans = 0;
        for (int i=0; i<d; i++){
            for (int p=0; p<f; p++){
                cin>>arr[i][p];
            }
        }

        for (int i=0; i<d; i++){
            int sum = 0;
            for (int p= 0; p<f; p++){
                sum+=arr[i][p];
            }
            // cout<<"Row: "<<i<<" "<<sum<<'\n';
            if (sum % 13 == 0){
                ans += sum/13;
                
            }
        }

        for (int p=0; p<f; p++){
            int sum = 0;
            for (int i=0; i<d; i++){
                sum+=arr[i][p];
            }
            // cout<<"Column: "<<p<<" "<<sum<<'\n';
            if (sum % 13 == 0){
                ans += sum/13;
                
            }
        }

        cout<<ans<<endl;
    }
    
    
    return 0;
}
