#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct game {
    string type;
    int time, cheese, gold;
};

signed main() {
    int n; cin >> n;
    vector<game> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].type >> a[i].time >> a[i].cheese >> a[i].gold;
    }
    int k; cin >> k;
    vector<game> process;
    int cheese = 0, gold = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].time <= k) {
            if (a[i].type == "CAUGHT") {
                cheese+=a[i].cheese;
                gold += a[i].gold;
            }
            else {
                cheese -= a[i].cheese;
                gold -= a[i].gold;
            }
        }
    }
    cout << cheese << " " << gold;
}