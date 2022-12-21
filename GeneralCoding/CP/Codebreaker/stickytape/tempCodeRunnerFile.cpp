#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,m;
    cin>>n>>m;

    int arr[m+5];
    memset(arr, 0, sizeof arr);
    // arr[0] = 0;
    for (int i=0; i<m; i++){
        cin>>arr[i];
    }

    sort(arr, arr+m);

    int ans = 0;
    deque<int>dq;

    int counter = 0;
    while (counter < m){
        int a,b;
        // if (counter = m-1){
        //     a = arr[counter];
        //     b = dq[0];
        // }
        if (dq.size() >= 2 && (counter >= m || (dq[0] < arr[counter] && dq[1] < arr[counter]))){
            a = dq[0];
            b = dq[1];
            dq.pop_front();
            dq.pop_front();
        }
        else if(dq.size() >= 1 && (counter == m-1 || dq[0] < arr[counter+1])){
            a = arr[counter];
            b = dq[0];
            dq.pop_front();
            counter++;
        }
        else{
            a = arr[counter];
            b = arr[counter+1];
            counter += 2;
        }
        // int a = arr[counter];
        // cout<<a<<' '<<counter<<'\t';
        // counter ++;

        // if (dq.size() > 0){

        // }

        // int b = arr[counter];
        // cout<<a<<' '<<counter<<'\n';
        // counter++;

        // cout<<a<<' '<<b<<'\n';

        ans += (a+b);

        dq.push_front(a+b);
    }

    cout<<ans;
    
    return 0;
}
