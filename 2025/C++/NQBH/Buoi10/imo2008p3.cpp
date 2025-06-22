#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, b; 
const double oo = 1e9 + 7;

signed main() {
    int cnt = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        int new_num = i * i + 1;
        double limit = 2.0 * i + sqrt(2 * i);

        int temp = new_num;
        bool ok = false;
        for (int j = 2; j * j <= new_num; j++) {
            if (temp % j == 0) {
                while (temp % j == 0) {
                    temp /= j;
                }
                if (j > limit) {
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) {
            if (temp > 1) {
                if (temp > limit) {
                    ok = true;
                }
            }
        }
        if (ok) {
            cnt++;
        }
    }
    cout << cnt;
}   