#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
map<int,int> ma;

bool compare(pair<int,int>& f, pair<int,int>& s) {
    return (f.second < s.second);
}

int main() {

    int n; cin >> n;

    int maxTime = 0;
    vector<pair<int,int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;;
    }
    sort(a.begin() + 1, a.end(), compare);

    int f[n + 1];
    memset(f, 0, sizeof(f));
    // f[i] : tong thoi gian lon nhat khi xet den doan i
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        // Khong chon doan i
        // Chon doan i -> tim f[j] gan nhat (rj < li)
        int ans = -1;
        int l = 1, r = i - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (a[mid].second < a[i].first) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (ans == - 1) {
            f[i] = max(f[i - 1], a[i].second - a[i].first + 1);
        }
        else {
            f[i] = max(f[i - 1], f[ans] + a[i].second - a[i].first + 1);
        }
    }

    int ans = *max_element(f + 1, f + n + 1);
    cout << ans;

}