#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, q;
string s;

void subtask1() {
    int l, r; cin >> l >> r;
    l++, r++;
    vector<int> freq(26, 0);
    for (int i = l; i <= r; i++) {
        freq[s[i] - 'a']++;
    }
        
    int odd = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) odd++;
    }
    int ans = odd / 2;
    cout << ans << endl;
}

void subtask2() {
    
    vector<vector<int>> freq(n + 1, vector<int>(26, 0));

    for (int i = 1; i <= n; i++) {
        freq[i] = freq[i - 1];
        freq[i][s[i] - 'a']++;
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l++, r++;
        vector<int> cur(26, 0);

        for (int i = 0; i < 26; i++) {
            cur[i] = freq[r][i] - freq[l - 1][i];
        }
    
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (cur[i] % 2 == 1) odd++;
        }

        int ans = odd / 2;

        cout << ans << endl;
    }
}

signed main() {

    cin >> n >> q;
    cin >> s;
    s = " " + s;
    if (q == 1) return subtask1(), 0;
    else return subtask2(), 0;
}