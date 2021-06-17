#include <cstdio>
#include <vector>
using namespace std;

vector<short int> vc;

int main(){
    int n; scanf("%i", &n);
    short int a;
    for(int i=0;i<n;i++){
        scanf("%hi",&a);
        vc.push_back(a);
    }
    short int k; scanf("%hi",&k);
    for(auto i:vc){
        printf("%i\n", i+k);
    }
}
