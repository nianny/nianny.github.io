#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int h,w;
    cin>>h>>w;

    int arr[h+5][w+5];
    bool wall[h+5][w+5];

    for (int i=1; i<=h; i++){
        for (int p=1; p<=w; p++){
            char c;
            cin>>c;

            if (c == '.') {
                wall[i][p] = false;
            }
            else {
                wall[i][p] = true;
            }
        }
    }
    memset(arr, 0, sizeof(arr));

    arr[1][1] = 1;

    for (int i=2; i<=w; i++){
        if (wall[1][i] == false) {
            arr[1][i] = arr[1][i-1];
        }
        else {
            arr[1][i] = 0;
        }
    }

    for (int i=2; i<=h; i++){
        for (int p=1; p<=w; p++){
            if (wall[i][p]) {
                arr[i][p] = 0;
            }
            else {
                if (p == 1) {
                    arr[i][p] = arr[i-1][p];
                }
                else {
                    arr[i][p] = (arr[i-1][p] + arr[i][p-1]) % 1000000007;
                }
            }
        }
    }

    // for (int i=1; i<=h; i++){
    //     for (int p=1; p<=w; p++){
    //         cout<<arr[i][p]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<arr[h][w];


    
    
    return 0;
}
