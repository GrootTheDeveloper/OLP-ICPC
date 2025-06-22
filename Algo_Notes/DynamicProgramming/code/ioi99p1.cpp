#include <bits/stdc++.h>
using namespace std;

int main() {
    int F, V; cin >> F >> V;
    vector<vector<int>> a(F + 1, vector<int>(V + 1)), f(F + 1, vector<int>(V + 1, INT_MIN));

    for (int i = 1; i <= F; i++) {
        for (int j = 1; j <= V; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 1; j <= V - F + 1; j++) {
        f[1][j] = a[1][j];
    }

    for (int i = 2; i <= F; i++) {
        for(int j = i; j <= V - F + i; j++) {
            for (int k = i - 1; k < j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][k]);
            }
            f[i][j] += a[i][j];
        }
    }

    int ans = INT_MIN;
    for (int j = F; j <= V; j++) {
        ans = max(ans, f[F][j]);
    }
    cout << ans;

    int i = F;
    vector<int> res;

    while (i >= 1) {
        for (int j = i; j <= V - F + i; j++) {
            if (f[i][j] == ans) {
                res.push_back(j);
                ans -= a[i][j];
                i--;
                break;
            }
        }
    }
    cout << endl;
    reverse(res.begin(), res.end());
    for (auto p : res) {
        cout << p << " ";
    }
}