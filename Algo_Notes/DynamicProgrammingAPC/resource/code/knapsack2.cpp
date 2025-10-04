#include <bits/stdc++.h>
#define int long long
const int oo = 1e9 + 7;
using namespace std;

struct item {
    int w, v;
};

signed main() {
    int n, w; cin >> n >> w;
    vector<item> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].w >> a[i].v;
    }    
    int MAXV = 1e5;
    // dp[i][j] : khoi luong nho nhat co the khi xet i do vat dau tien, tong gia tri la j
    vector<vector<int>> dp(n + 1, vector<int>(MAXV + 5, oo));

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAXV; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i].v < 0) continue;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i].v] + a[i].w);
        }
    }

    int ans = 0;
    for (int j = 0; j <= MAXV; j++) {
        if (dp[n][j] <= w)
            ans = j;
    }
    cout << ans;
}