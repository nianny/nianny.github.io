#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,k,x;
    cin>>n>>k>>x;
    int current = x;
    for (int i=0; i<k; i++){
        
        string a = to_string(current);
        bool flag = false;
        for (auto i: a){
            if (i == '7'){
                cout<<"UP!"<<'\n';
                flag = true;
                break;
            }
        }

        if (!flag){
            if (current % 7 ==0){
                cout<<"UP!"<<'\n';
            }
            else{
                cout<<current<<'\n';
            }
        }

        

        current += n;
    }
    
    return 0;
}
