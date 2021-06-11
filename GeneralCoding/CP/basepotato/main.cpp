#include <bits/stdc++.h>
using namespace std;
#define int long long


string fromDeci(int base, int inputNum)
{
    int index = 0; 
    char res[5];
    while (inputNum > 0){
        cout<< inputNum / base << ' ';
        inputNum %= base;
    }
//    res[index] = '\0';
    return string(res);
}


int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    fromDeci(2, 2);    
    return 0;
}
