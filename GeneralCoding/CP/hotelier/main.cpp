#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int arr[10];
int32_t main() {
    hallo;
    int n;
    cin>>n;
    
    for (int i=0; i<n; i++){
        char a;
        cin>>a;

        if(a=='L'){
            for (int p=0; p<10; p++){
                if (arr[p] == 0){
                    arr[p] = 1;
                    break;
                }
            }
        }
        else if (a=='R'){
            for (int p=9; p>=0; p--){
                if (arr[p] == 0){
                    arr[p] = 1;
                    break;
                }
            }
        }

        else{
            arr[(int)(a-'0')] = 0;
        }
    }

    for (int i=0; i<10; i++){
        cout<<arr[i];
    }
    return 0;
}
