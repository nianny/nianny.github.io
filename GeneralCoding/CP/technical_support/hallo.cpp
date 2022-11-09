#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int count=0;
    priority_queue<pair<int,int>>pq;
    for (int i=1; i<=n; i++){
        int a;
        cin>>a;
        pq.push(make_pair(a,i));
    }
    int points[n+2];
    memset(points,0,sizeof(points));
    int maximum=0;
    for (int i=1; i<=n; i++){
        int first = pq.top().first;
        int second = pq.top().second;
        pq.pop();
        //points[second]=1;
        //if (first == pq.top().first){
            // if (points[second-1]==0 && points[second+1]==0){
            //     count++;
            //     points[second]=1;
            // }
            // else if (points[pq.top().second-1]==0 && points[pq.top().second+1]==0){
            //     count++;
            //     points[pq.top().second]=1;
            //     pq.pop();
            //     pq.push(make_pair(first,second));
            // }
            // //compare whether the thingi is first better or second better (if nothing next to them)
            
            

            // else if (points[pq.top().second-1]==0 || points[pq.top().second+1]==0){
            //     pq.pop();
            //     pq.push(make_pair(first,second));
            //     points[pq.top().second]=1;
            // }

            // else if (points[second-1]==1 && points[second+1]==1){
            //     count--;
            //     points[second]=1;
            // }
            // else{
            //     points[pq.top().second]=1;
            // }
        //}

        if (true){
            points[second]=1;
            if (points[second-1]==0 && points[second+1]==0){
                count++;
            }
            else if (points[second-1]==1 && points[second+1]==1){
                count--;
            }
        }

        maximum = max(count,maximum);

    }

    cout<<maximum;
}