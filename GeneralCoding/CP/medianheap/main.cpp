#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        string a;
        int b;
        cin>>a>>b;
        if (a == "PUSH"){
            pq.push(b);

            if (pq.size() - pq2.size() > 1){
                pq2.push(pq.top());
                pq.pop();
            }
        }
        else{
            pq.pop();
            
        }
    }
    // pq2.push(5);
    // pq2.push(4);

    // cout<<pq2.top();


    
    
    return 0;
}
