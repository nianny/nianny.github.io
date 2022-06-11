#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    speed;
    int n;
    int arr[12];

    for (int i=2; i<12; i++){
        arr[i] = 4;
    }
    arr[10] = 12;

    int sum = 0;
    cin>>n;
    for (int i=0; i<n; i++){
        int num;
        cin>>num;

        sum += num;
        arr[num] -= 1;
    }
    int x = 21-sum;

    int possible = 0;
    for (int i=2; i<=min(x, (int)11); i++){
        possible += arr[i];
    }

    for (int i=min(x, (int)11); i <= 11; i++){
        possible -= arr[i];
    }

    if (possible > 0){
        cout<<"VUCI";
    }
    else{
        cout<<"DOSTA";
    }
    
    return 0;
}
