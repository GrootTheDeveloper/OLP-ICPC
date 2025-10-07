#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2*1e6;

signed main() {
    int left, right; cin >> left >> right;

    int s_l = sqrt(left), s_r = sqrt(right);

    int in_left = s_l, in_right = s_r;

    if (s_l * s_l < left) {
        in_left++;
    }

    if (s_r * s_r <= right) {
        in_right--;
    }

    int ans = 0;
    for (int i = in_left; i <= in_right; i++) {
        ans += i * ((i + 1) * (i + 1) - i * i);
    }
    ans += (in_left - 1) * (in_left * in_left - left);
    ans += (in_right + 1) * (right - s_r * s_r + 1);
    cout << ans;
}