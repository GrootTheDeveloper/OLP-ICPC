#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main(){
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n + 1), inv(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];

        string s; cin >> s;
        s = " " + s;
        for (int i = 1; i <= n; i++) inv[p[i]] = i;

        vector<int> cycles(n + 1, -1);
        vector<int> done(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (done[i]) continue;

            vector<int> cycle;
            int u = i;
            do {
                cycle.push_back(u);
                u = p[u];
            } while (u != i);

            int cnt_black = 0;
            for (int v : cycle) {
                if (s[inv[v]] == '0') cnt_black++;
            }

            for (int v : cycle) {
                cycles[v] = cnt_black;
                done[v] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << cycles[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
