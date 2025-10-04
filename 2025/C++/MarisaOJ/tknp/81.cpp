#include <bits/stdc++.h>
#define int long long

const int oo = 1e9 + 7;
using namespace std;

struct candy{
    int numCandy;
    int weight;
};

bool compare (candy &cur, candy &other) {
    return cur.weight < other.weight;
}

signed main() {
    int n, q; cin >> n >> q;
    vector<candy> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].numCandy >> a[i].weight;
    }
    sort(a.begin() + 1, a.end(), compare);
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[i].numCandy;
    }
    while (q--) {
        int x; cin >> x;
        int l = 1, r = n;
        int ans = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            if (f[mid] >= x) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << a[ans].weight << endl;
    }
}