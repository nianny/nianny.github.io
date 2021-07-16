#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi;
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        deque<char>str;
        string a;
        cin>>a;
        for (int p=0; p<a.length(); p++){
            str.push_back(a[p]);
        }
        bool front = true;
        while(!str.empty()){
            if (str.size() == 1){
                break;
            }
            if (front){
                if (str[0]-1 == str[1]){
                    str.pop_front();
                }
                else if (str[0]-1 == str.back()){
                    front = false;
                    str.pop_front();
                }
                else{
                    cout<<"NO";
                    break;
                }
            }
            else {
                if (str.back()-1 == str[str.size()-2]){
                    str.pop_back();
                }
                else if (str.back()-1 == str.front()){
                    front = true;
                    str.pop_back();
                }
                else {
                    cout<<"NO";
                    break;
                }
            }
        }
        if (str.size() == 1){
            cout<<"YES";
        }
        cout<<'\n';
    }

    
    return 0;
}
