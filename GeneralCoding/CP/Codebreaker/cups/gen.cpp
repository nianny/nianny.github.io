#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    vector<int> v;    // creates a new vector called “v” that stores ints
    v.push_back(1);   // pushing to the back is O(1), vector is now [1]
    v.push_back(2);   // vector is now [1,2]
    v.push_back(3);   // vector is now [1,2,3]
    cout << v[0];     // indexing is still O(1), prints 1
    v[1] += 2;        // vector is now [1,4,3]
    v.pop_back();     // popping from the back is also O(1), vector is now [1,4]
    cout << v.size(); // the number of items in the vector, prints 2

}