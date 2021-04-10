#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++) {
        int n;
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; j ++) {
            cin >> arr[j];
        }
        int preVal = arr[0];
        int ans = 0;
        for (int j = 1; j < n; j ++) {
            int tmp = arr[j];
            int lenDiff = to_string(preVal).length()-to_string(tmp).length();
            string s = "";
            for (int k = 0; k < lenDiff; k ++) {
                s += '9';
            }
            tmp = stoi(to_string(tmp)+s);
            
                        //cout << arr[j] << " " << tmp << " " << preVal << endl;

            if (tmp <= preVal) {
                ans += lenDiff+1;
                string s = "";
                for (int k = 0; k <= to_string(preVal).length()-to_string(tmp).length(); k ++) {
                    s += '0';
                }
                arr[j] = stoi(to_string(tmp)+s);
                preVal = arr[j];
                continue;
            }
            while (arr[j] <= preVal && to_string(arr[j]).length() != to_string(preVal).length()) {
                arr[j] *= 10;
                ans += 1;
            }
            while (arr[j] <= preVal) {
                arr[j] += 1;
            }
            preVal = arr[j];
        }
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
}