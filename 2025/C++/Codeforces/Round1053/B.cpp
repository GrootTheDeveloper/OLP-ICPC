#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<char>ch(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ch[i];
        }
        set<int> ms;
        for (int i = 1; i <= m; i++) {
            int x; cin >> x;
            ms.insert(x);
        }
        int pos = 1;
        for (int i = 1; i <= n; i++) {
            if (ch[i] == 'A') {
                pos++;
            }
            else {
                
            }
        }
    }
}