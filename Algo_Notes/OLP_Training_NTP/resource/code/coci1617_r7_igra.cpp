#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> cnt(3, 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }

    vector<vector<int>> suf(n + 1, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            suf[i][j] = suf[i + 1][j];
        }
        suf[i][t[i] - 'a'] = suf[i + 1][t[i] - 'a'] + 1;
    }

    string ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (cnt[j] == 0) continue;
            if (j == (t[i] - 'a')) continue;
            cnt[j]--;
            int remain = n - (i + 1);
            bool ok = true;
            for (int k = 0; k < 3; k++) {
                int c = cnt[k];
                int allow = remain - suf[i + 1][k];
                if (allow >= c) continue; // thỏa
                ok = false;
                break;
            }
            if (ok) {
                char temp = 'a' + j;
                ans.push_back(temp);
                break;
            }
            else {
                cnt[j]++;
            }
        }
    }

    cout << ans;

    return 0;
}
