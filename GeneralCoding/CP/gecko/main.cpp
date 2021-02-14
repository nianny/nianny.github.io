#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[510][510];
int h,w;
int results[510][510];
int dp(int x, int y){
    //cout<<x<<' '<<y<<'\n';
    //cout<<'a'<<'\n';
    if (results[x][y] != -1) return results[x][y];
    if (y == h-1){
        return arr[x][y];
    }
    int sum = 0; 
    for (int i=-1; i<2; i++){
        if (!((i+x) < 0 or (i+x) >= w)){
            sum = max(sum, dp(i+x, y+1));
            //cout<<i+x<<' '<<y+1<<'\t';
        }
    }
    sum += arr[x][y];
    //cout<<x<<' '<<y<<' '<<sum<<'\n';
    return results[x][y]=sum;

    ///return max(max(dp(x-1,y-1), dp(x,y-1)), dp(x+1,y-1) + arr[x][y]);
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    
    cin>>h>>w;
    memset(results, -1, sizeof(results));

    for (int i=0; i<h; i++){
        for (int p=0; p<w; p++){
            cin>>arr[p][i];
        }
    }

    int maximum = 0;
    for (int i=0; i<w; i++){
        maximum = max(maximum, dp(i, 0));
    }

    cout<<maximum;



    
    return 0;
}