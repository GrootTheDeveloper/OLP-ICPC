#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MAXN = 1e6;
const int mod = 1e9 + 7;
int qpow(int n, int exp, int MOD) {
    if (exp == 0) return 1;
    if (exp == 1) return n;
    int temp = qpow(n, exp / 2, MOD);
    temp %= MOD;
    if (exp % 2 == 0) return temp * temp % MOD;
    return temp * temp % MOD * n % MOD;
}
signed main() {
    string s; cin >> s;
    map<char,int> ma;
    for (auto c : s) ma[c]++;
    vector<int> fact(MAXN + 5, 1), invfact(MAXN + 5, 1);
    for (int i = 2; i <= MAXN; i++) {
        (fact[i] = fact[i - 1] * i) %= mod;
    }
    invfact[MAXN] = qpow(fact[MAXN], mod - 2, mod);
    for (int i = MAXN; i > 0; i--) (invfact[i - 1] = invfact[i] * i) %= mod;
    
    int ans = fact[s.size()];
    // cout << ans << endl;
    for (auto [f, s] : ma) {
        // cout << f << " " << s << endl;
        (ans *= invfact[s]) %= mod;
    }
    cout << ans;

}
