#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, C;
vector<pair<int,int>> arr;

bool checkSubtask1() {
    return true;
}

bool ok(int x) {
    int best = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && arr[i].first - arr[i - 1].first > x)
            cur = 0;
        cur += arr[i].second;
        best = max(best, cur);
    }
    return best >= C;
}

void doSubtask1() {
    sort(arr.begin(), arr.end());
    int lo = 0, hi = arr.back().first - arr.front().first, ans = hi;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) ans = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    cout << ans;
}

signed main() {

    cin >> n >> C;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    arr.resize(n);
    for (int i = 0; i < n; i++) arr[i] = {a[i], b[i]};

    if (checkSubtask1()) return doSubtask1(), 0;
}
