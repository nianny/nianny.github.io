#include <bits/stdc++.h>
using namespace std;
#define int long long
// arr[j] is the array of elements before current element
// arr[i] is array of elements including the current element
// LIS[i] is the number of elements, excluding current element
// LIS[i] is the number of elements, including current element

int arr[5105];

int32_t main(){
    int n; cin >> n;
    int i; int j;
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int lis[n]; int ans;

    for (int i=0; i<n; i++){
        lis[i] = 0; 
        for (int j=0; j<i; j++){
    
            if (arr[j] < arr[i]){
                lis[i] = lis[i] + 1;
            }
            
        }
        if(lis[i] == 0){
            lis[i] = 1; 
        }
    }
    for(int i = 0; i < n; i++){
        ans = max(ans, lis[i]);
    }
cout << ans;
}

