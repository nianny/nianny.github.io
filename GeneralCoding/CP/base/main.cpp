#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    string a;
    cin>>a;
    int b,c;
    cin>>b>>c;
    map<char,int>b_map;
    map<int,char>c_map;
    for (int i=0; i<b; i++){
        if (i<10){
            b_map[(char)i+'0'] = i;
        }
        else {
            b_map[(char)i-10+'A'] = i;
        }
    }

    for (int i=0; i<c; i++){
        if (i<10){
            c_map[i] = (char)i+'0';
        }
        else {
            c_map[i] = (char)(i-10+'A');
        }
    }
    int multiple = 1;
    int num = 0;
    for (int i=a.length()-1; i>=0; i--){
        num += (multiple * b_map[a[i]]);
        multiple *= b;
    }
    string ans = ""; 
    while (num > 0){
        ans = c_map[num % c] + ans;
        num /= c;
    }
    cout<<ans;

    return 0;
}
