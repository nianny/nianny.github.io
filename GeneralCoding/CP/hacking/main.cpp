#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

pair<int,int> arr[500005];

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    int n,m;
    cin>>n>>m;
    int num;
    int x,y,c;



    for (int i=0; i<m; i++){
        // int num;
        cin>>num;

        if (num == 1){
            // int x,y;
            cin>>x>>y;

            arr[x].first++;
            arr[y].second++;
        }

        else if (num == 2){
            // int x,y;
            cin>>x>>y;

            arr[x].first--;
            arr[y].second--;
        }

        else if (num == 3){
            // int c;
            cin>>c;
            cout<<arr[c].second<<endl;
        }

        else if (num == 4){
            // int c;
            cin>>c;
            cout<<arr[c].first<<endl;
        }
    }
    
    
    return 0;
}
