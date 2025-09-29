#include <bits/stdc++.h>
using namespace std;

int n, q;
string s;

bool checkSubtask1() {
    return q == 1;
}

void doSubtask1() {
    int l, r; cin >> l >> r;
    l++, r++;
    vector<int> cnt(26, 0);
    for (int i = l; i <= r; i++) {
        cnt[s[i] - 'a']++;
    }

    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) res++;
    }
    int ans = res / 2;
    cout << ans;
}

void doSubtask2() {
    vector<vector<int>> f(n + 1, vector<int>(26, 0));
    // int f[n + 1][26];
    // f[i]['a'..'z'] số lần xuất của [a..z] trong i phần tử đầu tiên
    
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        f[i][s[i] - 'a']++;
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l++, r++;
        vector<int> cnt(26, 0);

        for (int i = 0; i < 26; i++) {
            cnt[i] = f[r][i] - f[l - 1][i];
        }
        
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) res++;
        }
        int ans = res / 2;
        cout << ans << endl;
    }
}

signed main() {
    cin >> n >> q;
    cin >> s;
    s = " " + s;

    if (checkSubtask1()) return doSubtask1(), 0;
    return 0;
}
