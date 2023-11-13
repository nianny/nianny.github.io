#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, a, b, s;
string S;
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int i=0; i<t; i++){
        int x;
        cin >> x;
        a = x;
        b = 0;
        S = to_string(a); 
	    s = S.size();
	    while ((a % 11111111 % 1111111 % 111111 % 11111 % 1111 % 111 % 11 != 0) && s > 2){
	        a -= pow(10, s-1); // remove highest 10...0
	        b++;
	        S = to_string(a);
	        s = S.size(); // calculate no. of digits now
	        
	    }
	    if (a % 11 == 0 && b <= a / 11){  // if a is divisible by 11 & count is less than/equal to number of 11s left
	        cout << "YESa" << " ";
  	    }
  	    else if (a % 11111111 % 1111111 % 111111 % 11111 % 1111 % 111 % 11 == 0){ // if a is divisible by 11...1
  	        cout << "YESb" << " ";
            cout<<a;
  	    }
	    else {
	        cout << "NO" << " ";
	    }
    }
  return 0;
}