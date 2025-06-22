#include <bits/stdc++.h>
#define int long long
using namespace std;

int calc(int x1,int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<pair<int, int>> may_phat, thiet_bi;
        
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] == 1) may_phat.push_back({i, j});
                else if (a[i][j] == 2) thiet_bi.push_back({i, j});
            }
        }

        vector< int > nearest;
        for (int i = 0; i < thiet_bi.size(); i++) {
            int min_dist = 1e9;
            for (int j = 0; j < may_phat.size(); j++) {
                int temp = calc(thiet_bi[i].first, thiet_bi[i].second,
                                may_phat[j].first, may_phat[j].second);
                if (min_dist > temp) {
                    min_dist = temp;
                }
            }
            nearest.push_back(min_dist);
        }

        int ans = 0;
        for (auto it : nearest) {
            ans = max(it, ans);
        }
        cout << ans << endl;
    }
}
