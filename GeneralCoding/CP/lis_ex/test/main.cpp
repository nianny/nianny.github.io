#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> disc(vector <int> V) {
	vector <int> dis = V;
	sort(dis.begin(),dis.end());
	dis.resize(unique(dis.begin(),dis.end()) - dis.begin());
	for (int i =0;i<(int)V.size();i++) {
		V[i] = lower_bound(dis.begin(),dis.end(),V[i]) - dis.begin() + 1;
	}
	return V;
}
int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    vector<int>a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(2);
    for (int i=0; i<3; i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';

    a = disc(a);
    for (int i=0; i<3; i++){
        cout<<a[i]<<' ';
    }
    return 0;
}