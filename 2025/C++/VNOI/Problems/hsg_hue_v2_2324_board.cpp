#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BOARD.INP", "r", stdin);
    freopen("BOARD.OUT", "w", stdout);
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1)), b(n + 1, vector<char>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }

    vector<pair<int,int>> ans;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                ans.push_back({i,j});
                a[i][j] = (a[i][j] == 'B' ? 'W' : 'B');
                a[i + 1][j] = (a[i + 1][j] == 'B' ? 'W' : 'B');
                a[i][j + 1] = (a[i][j + 1] == 'B' ? 'W' : 'B');
                a[i + 1][j + 1] = (a[i + 1][j + 1] == 'B' ? 'W' : 'B');
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != b[i][j]) {
                cout << "NO"; return 0;
            }
        }
    }
    cout << "YES\n" << ans.size() << endl;
    for (auto [l, r] : ans) {
        cout << l << " " << r << endl;
    }
    return 0;
}