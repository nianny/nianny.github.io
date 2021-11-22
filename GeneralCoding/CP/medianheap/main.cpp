#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        string a;
        int b;
        cin>>a;;
        if (a == "PUSH"){
            cin>>b;
            if (!pq2.empty() && b > pq2.top()){
                pq2.push(b);

                if (pq2.size() > pq.size()){
                    pq.push(pq2.top());
                    pq2.pop();
                }
            }
            else {
                pq.push(b);

                if (pq.size() - pq2.size() > 1){
                    pq2.push(pq.top());
                    pq.pop();
                }
            }
        }
        else{
            pq.pop();
            if (pq.size() < pq2.size()){
                pq.push(pq2.top());
                pq2.pop();
            }
        }

        // for (auto it: pq){
        //     cout<<it<<" ";
        // }
        // for (auto it: pq2){
        //     cout<<it<<" ";
        // }
        
    }
    while (pq.size()){
        pq2.push(pq.top());
        pq.pop();
    }

    while(pq2.size()){
        cout<<pq2.top()<<" ";
        pq2.pop();
    }
    // pq2.push(5);
    // pq2.push(4);

    // cout<<pq2.top();


    
    
    return 0;
}
