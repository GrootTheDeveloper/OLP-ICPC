#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string s; cin >> s;
        char ch[7];
        for (int i = 0; i < 7; i++) {
            ch[i] = 0;
        }
        int round = 1;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ch[s[i] - 'A']++;
        }
        while(m > 0) {
            int check = 0;
            for (int i = 0; i < 7; i++) {
                if (ch[i] < round) {
                    check++;
                    ch[i]++;
                }
            }
            round++;
            m--;
            ans += check;
        }
        cout << ans << endl;
    }
}
