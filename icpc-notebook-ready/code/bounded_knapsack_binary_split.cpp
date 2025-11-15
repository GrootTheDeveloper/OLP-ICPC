#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, S;
    if (!(cin >> n >> S)) return 0;

    struct Item { int w; long long v; };
    vector<Item> items;
    items.reserve(n * 15);

    for (int i = 0; i < n; ++i) {
        int w, v, a; 
        cin >> w >> v >> a;
        for (int k = 1; a > 0; k <<= 1) {
            int take = min(k, a);
            a -= take;
            items.push_back({ w * take, 1LL * v * take });
        }
    }
    vector<long long> dp(S + 1, 0);
    for (auto &it : items) {
        int W = it.w; long long V = it.v;
        if (W > S) continue;
        for (int s = S; s >= W; --s) {
            dp[s] = max(dp[s], dp[s - W] + V);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
