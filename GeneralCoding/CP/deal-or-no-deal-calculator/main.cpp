#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    int n;
    cin>>n;

    int arr[11] = {0, 100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
    int sum = 0;
    for (int i=1; i<=10; i++){
        sum += arr[i];
    }
    for (int i=0; i<n; i++){
        int num;
        cin>>num;
        sum -= arr[num];
    }
    int bank;
    cin>>bank;
    sum /= (10-n);
    if (bank > sum){
        cout<<"deal";
    }
    else{
        cout<<"no deal";

    return 0;
}
