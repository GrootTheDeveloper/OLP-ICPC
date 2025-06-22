#include <bits/stdc++.h>
#define int long long
using namespace std;

const int SIZE = 300005;
const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q; cin >> n >> q;
    vector<int> person(n + 1, 0), lastCT(n + 1, 0), money(n + 1, 0);
    int CT = 0;

    for (int Q = 0; Q < q; Q++) {
        int type; cin >> type;
        if (type == 1) {
            int p, x; cin >> p >> x;
            int delta = ((person[p] % mod) * ((CT - lastCT[p] + mod) % mod)) % mod;
            money[p] = (money[p] + delta) % mod;
            lastCT[p] = CT;
            person[p] += x;
        }
        else if (type == 2) {
            int v; cin >> v;
            CT += v;
        }
        else {
            int p; cin >> p;
            int delta = ((person[p] % mod) * ((CT - lastCT[p] + mod) % mod)) % mod;
            int ans = (money[p] + delta) % mod;
            lastCT[p] = CT;
            money[p] = 0;
            cout << ans << endl;
        }
    }

    return 0;
}