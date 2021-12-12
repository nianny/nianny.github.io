#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    int q;
    cin>>q;

    queue<int> left, right;

    for (int i=0; i<q; i++) {
        int n;
        cin>>n;


        if (n == 1){
            int x;
            cin>>x;

            right.push(x);

            if (right.size() > left.size()){
                left.push(right.front());
                right.pop();
            }
        }

        else{
            swap(left, right);
            
            if (right.size() > left.size()){
                left.push(right.front());
                right.pop();
            }
        }
    }


    while (!left.empty()){
        cout<<left.front()<<" ";
        left.pop();
    }

    while(!right.empty()){
        cout<<right.front()<<" ";
        right.pop();
    }
    
    return 0;
}


/*
7
1 1
1 2
2
1 3
1 4
1 5
2
*/