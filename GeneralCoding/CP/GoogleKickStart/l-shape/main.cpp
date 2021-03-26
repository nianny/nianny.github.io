#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int t;
    cin>>t;

    for (int p=0; p<t; p++){
        int r,c;
        cin>>r>>c;
        bool arr[r+5][c+5];

        for (int i=0; i<r; i++){
            for (int m=0; m<c; m++){
                cin>>arr[i][m];
            }
        }
        cout<<'\n';
        cout<<arr[3][0]<<'\n';
        int ans = 0;
        for (int i=0; i<r; i++){
            for (int m=0; m<c; m++){
                int a=0,b=0,c=0,d=0;
                
                for (int x=i; x>=0; x--){
                    if (!arr[x][m]){
                        break;
                    }   
                    a++;
                }

                for (int x = i; x<r; x++){
                    if (!arr[x][m]){
                        break;
                    }
                    b++;
                }

                for (int y=m; y>=0; y--){
                    if (!arr[i][y]){
                        break;
                    }   
                    c++;
                }

                for (int y = m; y<c; y++){
                    if (!arr[i][y]){
                        break;
                    }
                    d++;
                    cout<<'\n'<<i<<' '<<y<<' '<<"Called"<<'\n';
                }
                if (a<2){
                    a = 0;
                }
                if (b<2){
                    b=0;
                }
                if (c<2){
                    c=0;
                }
                if (d<2){
                    d=0;
                }

                ans += (min(a, c/2)+min(a,d/2));
                ans += (min(b, c/2)+min(a,d/2));
                ans += (min(c, a/2)+min(c,b/2));
                ans += (min(d, a/2)+min(d,b/2));

                cout<<i<<' '<<m<<' '<<ans<<'\t'<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
            }
        }
        ans = ans/2;
        cout<<ans<<'\n';
    }
    return 0;
}