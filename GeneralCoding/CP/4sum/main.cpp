#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

string hallo (int number_of_o){
  	string s = "Hall";
  	for (int i=0; i<number_of_o; i++){
      s+='o';
    }
    return s;
}
int32_t main() {
    cout<<hallo(5);
    return 0;
}
