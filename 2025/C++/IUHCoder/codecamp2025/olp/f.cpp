#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    string s, t; cin >> s >> t;
    if (s.size() > t.size()) swap(s,t);
    if (s.size() < t.size()) {
        cout << t.size();
        return 0;
    }
    if (s == t) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') cnt++;
        }
        cout << cnt;
        return 0;
    }

//    vector<int> cnt(t.size() + 1, 0);
    int idx = 0;
    while (idx < s.size() && s[idx] == t[idx]) idx++;
    int ans = t.size() - idx;
    for (int i = 0; i < idx; i++) {
        ans += t[i] - '0';
    }
    cout << ans;
}