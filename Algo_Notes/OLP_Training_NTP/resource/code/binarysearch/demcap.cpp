#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());

    for (int i = 1; i <= n; i++) {
        int nl = l - a[i], nr = r - a[i];

        int left = i + 1, right = n;

        /*
        Tìm a[j] sao cho nl <= a[j] <= nr mà j là lớn nhất

        Khi này, kết quả sẽ là (j - i - 1)

        l = 2, r = 4
        Khi xét i = 1

        nl = 1
        nr = 3
        Thì mình cần tìm a[j] mà 1 <= a[j] <= 3, và j là lớn nhất 
        [1, 2, 3]
        */

    }
}