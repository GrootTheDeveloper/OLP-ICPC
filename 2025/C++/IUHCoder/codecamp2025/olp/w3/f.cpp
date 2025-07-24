#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

/*
Contest-Motto: Làm bài 1 cách dơ bẩn như 1 OLP-er thật thụ
*/

vector< set<int> > node;
vector<int> na;

void build(int idx, int l, int r) {
    if (l == r) {
        node[idx].insert(na[l]);
        return;
    }
    int mid = l + r >> 1;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    node[idx] = node[idx * 2];
    for (auto x : node[idx * 2 + 1])
        node[idx].insert(x);
}

void query(int idx, int l, int r, int i, int j, set<int> &res) {
    if (j < l || r < i) return;
    if (i <= l && r <= j) {
        for (auto x : node[idx])
            res.insert(x);
        return;
    }
    int mid = l + r >> 1;
    query(idx * 2, l, mid, i, j, res);
    query(idx * 2 + 1, mid + 1, r, i, j, res);
}

signed main() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    vector<pair<int,int>> a_zip(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a_zip[i] = {a[i], i};
    }
    sort(a_zip.begin() + 1, a_zip.end());
    na.resize(n + 1);
    int cnt = 0;
    na[a_zip[1].second] = cnt;
    for (int i = 2; i <= n; i++) {
        if (a_zip[i].first != a_zip[i-1].first)
            na[a_zip[i].second] = ++cnt;
        else
            na[a_zip[i].second] = cnt;
    }
    node.resize(4 * n + 5, set<int>());
    build(1, 1, n);
    int maxVal = *max_element(na.begin() + 1, na.end());
    vector<vector<int>> dp(n + 1, vector<int>(maxVal + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        dp[i][na[i]] = dp[i - 1][na[i]] + 1;
    }
    while (q--) {
        int l, r;
        cin >> l >> r; 
        set<int> ms;
        query(1, 1, n, l, r, ms);
        int cnt = 0;
        for (auto it : ms) {
            if (dp[r][it] - dp[l - 1][it] == 2) {
                cnt++;
            }
        }
        cout << cnt << endl;
        
    }
    return 0;
}
