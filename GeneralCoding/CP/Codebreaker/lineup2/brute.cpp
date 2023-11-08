#include <bits/stdc++.h>
using namespace std;

int main(){
	stack <char> x;
	int L;
	char s;
	
	cin >> L;
	
	for (int i = 0; i < L; i++){
		cin >> s;

		if ((s == ')' || s=='}' || s==']') and x.empty()) {
			cout << "Invalid";
			return 0;
		}
	
		if (s == '(' || s == '{' || s == '['){
			x.push(s);
		}
		else if (s == ')' && x.top() == '('){
			x.pop();
		}
		else if (s == '}' && x.top() == '{'){
			x.pop();
		}
		else if (s == ']' && x.top() == '['){
			x.pop();
		}
        // cout<<x.size()<<'\n';
	}
	
	if (x.empty()){
		cout << "Valid";
	}
	else cout << "Invalid";
	
	return 0;
}