#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int l;
    cin>>l;

    stack<char>s;
    for (int i=0; i<l; i++){
        char a;
        cin>>a;

        if (a=='(' || a=='['||a=='{'){
            s.push(a);
        }
        else {
            if (s.empty()){
                cout<<"Invalid";
                return 0;
            }
            else if (a==')' && s.top() == '('){
                s.pop();
            }
            else if (a==']' && s.top() == '['){
                s.pop();
            }
            else if (a=='}' && s.top() == '{'){
                s.pop();
            }
        }
    }

    if (s.empty()){
        cout<<"Valid";
    }
    else {
        cout<<"Invalid";
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

