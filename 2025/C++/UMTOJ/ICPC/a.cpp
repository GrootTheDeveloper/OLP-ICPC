#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Cell {
    int x, y;
};

int calc(Cell a, Cell b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

signed main() {
    int n, m; cin >> n >> m;
    vector<Cell> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y;
    }
    Cell start = a[1];

    int cnt = 2;
    vector<bool> check(m + 1, false);
    check[1] = true;
    int ans = 0;
    while (cnt <= m) {
        int idx = -1;
        int minValue = 1e18;
        Cell cur = {-1, -1};
        for (int i = 2; i <= m; i++) {
            if (check[i]) continue;
            int val = calc(start, a[i]);
            if (val < minValue) {
                idx = i;
                minValue = val;
                cur = a[i];
            }
            else if (val == minValue) {
                if (a[i].x < cur.x) {
                    cur = a[i];
                    idx = i;
                }
                else if (a[i].x == cur.x && i < idx) {
                    cur = a[i];
                    idx = i;
                }
            }
        }
        cnt++;
        ans += minValue;
        check[idx] = true;
        start = a[idx];
    }
    cout << ans;
}