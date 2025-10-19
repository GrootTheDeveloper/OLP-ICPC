#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    if (m == 1) {
        int ans = 1e18;
        int l = 1;
        deque<int> dq;
        unordered_map<int,int> last;
        for (int r = 1; r <= n; r++) {
            if (last.count(a[r][1]) && last[a[r][1]] >= l) {
                l = last[a[r][1]] + 1;
            }
            last[a[r][1]] = r;
            while (dq.empty() == false && dq.front() < l) dq.pop_front();

            if (r - l + 1 > 1 && dq.empty() == false) {
                ans = min(ans, w[r] + w[dq.front()]);
            }
            while (dq.empty() == false && w[dq.back()] >= w[r]) dq.pop_back();
            dq.push_back(r);
        }
        cout << (ans == 1e18 ? -1 : ans);
        return 0;
    }

    int ans = 1e18;
    for (int i = 1; i < n; i++) {
        unordered_set<int> cur;
        for (int j = 1; j <= m; j++) {
            cur.insert(a[i][j]);
        }
        for (int j = i + 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                cur.insert(a[j][k]);
            }
            if (cur.size() == (j - i + 1) * m) {
                ans = min(ans, w[i] + w[j]);
            }
        }
    }
    cout << (ans == 1e18 ? -1 : ans);
}