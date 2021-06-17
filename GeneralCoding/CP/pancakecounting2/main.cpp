#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    vector<unsigned int>v;
    int n; scanf("%i", &n);
    int a;
    unsigned int b;
    for (int i=0; i<n/3; i++){
        b=0;
        scanf("%i", &a);
        b = a;
        scanf("%i", &a);
        b += a<<10;
        scanf("%i", &a);
        b += a<<20;
        v.push_back(b);
    }
    b=0;
    for (int i=0; i<n%3; i++){
        scanf("%i", &a);
        b += a<<(10*(i));
    }
    v.push_back(b);
    int k; scanf("%i", &k);
    for (int i=0; i<n/3; i++){
//        cout<<(v[i]>>10)<<'\n';
        printf("%u\n", ((v[i]<<22)>>22)+k);
        printf("%u\n", (v[i]<<12>>22)+k);
//        v[i] = (v[i]<<10)>>10;
        printf("%u\n",((v[i]<<2)>>22)+k);
    }
    for (int i=0; i<n%3; i++){
        printf("%u\n", ((v[v.size()-1]<<(2+(2-i)*10))>>22)+k);        
    }
    return 0;
}
