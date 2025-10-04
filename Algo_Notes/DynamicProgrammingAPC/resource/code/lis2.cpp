#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n + 1), f(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f[0] = 0;
    a[0] = 0;
    int len = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = len, pos = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            if (a[i] > a[f[mid]]) {
                pos = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        f[pos + 1] = i;
        if (pos + 1 > len) len++;
    }
    cout << len;
}