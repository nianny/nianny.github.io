#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi
    int t;
    cin>>t;
    map<char, string>words;
    words['0'] = "zero";
    words['1'] = "one";
    words['2'] = "two";
    words['3'] = "three";
    words['4'] = "four";
    words['5'] = "five";
    words['6'] = "six";
    words['7'] = "seven";
    words['8'] = "eight";
    words['9'] = "nine";
    for (int i=0; i<t; i++){
        string a;
        cin>>a;
        string combined = "";
        for (int p=0; p<a.length(); p++){
            combined += (words[a[p]]);
            if (p != a.length()-1){
                combined += ' ';
            }
        }
        combined[0] = toupper(combined[0]);
        cout<<combined;
        if (i!=t-1){    
            cout<<'\n';
        }
    }
    
    return 0;
}
