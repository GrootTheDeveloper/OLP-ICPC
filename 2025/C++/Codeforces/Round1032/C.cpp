#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        int maxValue = -1, maxCount = 0;

        vector<int> rowMax(n + 1, -1), colMax(m + 1, -1);
        vector<int> cntRowMax(n + 1, 0), cntColMax(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                maxValue = max(maxValue, a[i][j]);
                rowMax[i] = max(rowMax[i], a[i][j]);
                colMax[j] = max(colMax[j], a[i][j]);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == maxValue) {
                    cntRowMax[i]++;
                    cntColMax[j]++;
                    maxCount++;
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int overlap = (a[i][j] == maxValue ? 1 : 0);
                int remain = maxCount - cntRowMax[i] - cntColMax[j] + overlap;
                int outsideMax = (remain > 0 ? maxValue : maxValue - 1);
                int curMax = max({outsideMax, rowMax[i] - 1, colMax[j] - 1});
                ans = min(ans, curMax);
            }
        }

        cout <<  ans << endl;
    }
    return 0;
}