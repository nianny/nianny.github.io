#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    bool a[15];
    for(int i = 1; i <= 10; i++) a[i] = false;
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        char e = s[i - 1];
        if (e == 'L') for(int j = 1; j <= 10; j++) if (!a[j]) {a[j] = true; break;}
        if (e == 'R') for(int j = 10; j >= 1; j--) if (!a[j]) {a[j] = true; break;}
        if (e == '0') a[1] = false;
        if (e == '1') a[2] = false;
        if (e == '2') a[3] = false;
        if (e == '3') a[4] = false;
        if (e == '4') a[5] = false;
        if (e == '5') a[6] = false;
        if (e == '6') a[7] = false;
        if (e == '7') a[8] = false;
        if (e == '8') a[9] = false;
        if (e == '9') a[10] = false;
    }
    for (int i = 1; i <= 10; i++) {
        if (a[i]) cout << 1;
        else cout << 0;
    }

    return 0;
}