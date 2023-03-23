#include "wires.h"
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100005;
const int MAX_NUM_PRESS = 2000005;

const string err1("too many presses"), err2("invalid press"), err3("invalid order"), err4("wrong order");

static int vert[200005], num_press = 0, N, P = MAX_NUM_PRESS;
static string s;

int ans[200005], order[200005];

void print_WA(std::string MSG){
	std::cout << "Wrong Answer: " << MSG << '\n' << std::flush;
	exit(0);
}

int press(int x, int y){
	if (++num_press > P){
		print_WA(err1);
	}
	if (x < 1 || x > N || y < 1 || y > N){
		print_WA(err2);
	}
	return vert[x] < y;
}

void check_order(){
	int os = 0, zs = 0;
	for (int i = 0; i < 2*N; ++i){
		if (order[i] == 0) zs++;
		else if (order[i] == 1) os++;
		else print_WA(err3);
	}
	if (order[2*N] != -1) print_WA(err3);
	for (int i = 0; i < 2*N; ++i){
		if (order[i] != ans[i]) print_WA(err4);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> P;
	cin >> s;
	N = s.size()/2;
	int r = 0, b = 0;
	for (int i = 0; i < s.size(); ++i){
		if (s[i]-'0'==0){
			b++;
			vert[b] = r;
		}
		else{
			r++;
		}
	}
	for (int i = 0; i < s.size(); ++i){
		ans[i] = s[i] - '0';
		order[i] = -1;
	}
	order[2*N] = -1;
	wire(N,P,order);
	check_order();
	cout << "Accepted: " << num_press << '\n' << std::flush;
}

