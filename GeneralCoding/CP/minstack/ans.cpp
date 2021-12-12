#include <bits/stdc++.h>
#include "minstack.h"
using namespace std;


stack<int> stak;
stack<int> minstak;
// multiset<int> sat;

void push(int X) {
	stak.push(X);
    if (minstak.empty() || X <= minstak.top()) {
        minstak.push(X);
    }
}

void pop() {
    // sat.erase(sat.find(stak.top()));
    if (stak.top() == minstak.top()) {
        minstak.pop();
    }
    stak.pop();
}

int top() {
	return stak.top();
}

int getMin() {
	return minstak.top();
}

