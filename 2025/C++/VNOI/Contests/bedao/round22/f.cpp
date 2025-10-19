#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, q;
struct Query {
    int type, x, y;
};
vector<Query> a;
bool checkSubtask1() {
    for (int i = 1; i <= q; i++) {
        if (a[i].type == 1 || a[i].type == 0) {
            if (a[i].x != 1) return false;
        }
    }
    return true;
}

void doSubtask1() {
    set<int> pos;
    set<int> neg;
    pos.insert(1);
    for (int i = 1; i <= q; i++) {
        if (a[i].type == 0) {
            pos.insert(a[i].y);
        }
        else if (a[i].type == 1) {
            neg.insert(a[i].y);
        }
        else {
            int ans = -1;
            if (pos.find(a[i].x) != pos.end() && pos.find(a[i].y) != pos.end()) ans = 0;
            if (neg.find(a[i].x) != neg.end() && neg.find(a[i].y) != neg.end()) ans = 1;
            cout << ans << endl;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    a.resize(q + 1);
    for (int Q = 1; Q <= q; Q++) {
        int t, x, y; cin >> t >> x >> y;
        a[Q] = (Query){t, x, y};
    }
    return doSubtask1(), 0;
}