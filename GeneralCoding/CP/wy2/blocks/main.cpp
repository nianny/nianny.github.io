    #include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int x,y;
    cin>>x>>y;
    int arr[x][y];
    int num = 100;
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            cin>>arr[i][j];
            num = min(num, arr[i][j]);
        }
    }
    int sum = 0;
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            sum += abs(arr[i][j] - num);
        }
    }

    cout<<sum;
    
    
    return 0;
}
