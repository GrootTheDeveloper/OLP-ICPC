#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    string s; cin >> s;
    s = " " + s;
    int n = s.size() - 1;
    vector<int> f(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + (s[i] == '1' ? 1 : -1);
    }
    map<int,int> cnt;
    cnt[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += cnt[f[i]];
        cnt[f[i]]++;
    }
    cout << ans;
}