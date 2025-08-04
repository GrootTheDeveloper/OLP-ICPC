#include <bits/stdc++.h>
#define int long long
using namespace std;

const int SIZE = 300005;

bool check(vector<int> &a, vector<int>&b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}
signed main() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s;
    t = " " + t;
    vector<int> freq(26, 0);
    vector<int> cur(26, 0);
    for (int j = 1; j <= m; j++) {
        cur[t[j] - 'a']++;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        freq[s[i] - 'a']++;
    }
    
    int l = 1, r = m;
    while (r <= n) {
        if (check(freq,cur)) ans++;
        freq[s[l] - 'a']--;
        l++, r++;
        if (r > n) break;
        freq[s[r] - 'a']++;
    }
    cout << ans;
    return 0;
}