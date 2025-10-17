#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6;

signed main() {
    int n, k; cin >> n >> k;
    int x, arr, b, c;
    cin >> x >> arr >> b >> c;
    vector<int> a(n + 1);
    a[1] = x;
    for (int i = 2; i <= n; i++) {
        (a[i] = arr * a[i - 1] + b) %= c;
    }
    vector<int> ans;
    deque<int> bestIndex;
    for (int i = 1; i <= k; i++) {
        if (bestIndex.empty()) {
            bestIndex.push_back(i);
        }
        else {
            if (a[i] <= a[bestIndex.front()]) {
                bestIndex.push_front(i);
            }
            else {
                if (a[i] <= a[bestIndex.back()]) {
                    while (bestIndex.empty() == false && a[i] <= a[bestIndex.back()]) {
                        bestIndex.pop_back();
                    }
                    bestIndex.push_back(i);
                }
                else {
                    bestIndex.push_back(i);
                }
            }
        }
    }
    ans.push_back(a[bestIndex.front()]);
    for (int i = k + 1; i <= n; i++) {
        while (bestIndex.empty() == false && bestIndex.front() < (i - k + 1)) {
            bestIndex.pop_front();
        }
        if (bestIndex.empty()) {
            bestIndex.push_back(i);
        }
        else if (a[i] <= a[bestIndex.front()]) {
                while (bestIndex.empty() == false) bestIndex.pop_back();
                bestIndex.push_back(i);
        }
        else {
            if (a[i] <= a[bestIndex.back()]) {
                while (bestIndex.empty() == false && a[i] <= a[bestIndex.back()]) {
                    bestIndex.pop_back();
                }
                bestIndex.push_back(i);
            }
            else {
                bestIndex.push_back(i);
            }
        }

        ans.push_back(a[bestIndex.front()]);
    }

    int res = ans[0];
    for (int i = 1; i < ans.size(); i++) {
        res ^= ans[i];
    }
    cout << res;
}