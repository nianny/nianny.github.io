#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    for (int p=0; p<10; p++){
        int cost;
        cin>>cost;

        float y1,y2,y3,y4;
        cin>>y1>>y2>>y3>>y4;

        int n;
        cin>>n;

        int students[4] = {y1*n,y2*n,y3*n,y4*n};

        int sum = 0;
        int index = 0;
        for (int i=0; i<4; i++){
            if (students[i] > students[index]){
                index = i;
            }
            sum += students[i];
        }
        for (int i=0; i<4; i++){
            cout<<students[i]<<' ';
        }
        cout<<endl;
        students[index] += (n-sum);
        for (int i=0; i<4; i++){
            cout<<students[i]<<' ';
        }
        cout<<endl;
        int total = students[0]*12 + students[1]*10 + students[2]*7 + students[3]*5;
        if (total/2 > cost){
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
    }
    
    return 0;
}