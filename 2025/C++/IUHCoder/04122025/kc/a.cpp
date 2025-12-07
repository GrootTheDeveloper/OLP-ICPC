#include <bits/stdc++.h>
#define int long long
using namespace std;

int n; 
vector<int>a;
const int MOD = 1e9 + 7;

bool checkSubtask1() {
    return n <= 5000;
}
void doSubtask1() {
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[i];
    }
    int total = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int temp = f[j] - f[i - 1];
            (temp += MOD) %= MOD;
            (temp = temp % MOD * temp % MOD) %= MOD;
            (total += temp) %= MOD;
        }
    }
    cout << total;
}

void doSubtask2() {
    vector<int>f(n + 1, 0), g(n + 1, 0), h(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        (f[i] = f[i - 1] + a[i]) %= MOD;
        (g[i] = g[i - 1] + f[i]) %= MOD;
        (h[i] = h[i - 1] + f[i]  % MOD * f[i] % MOD) %= MOD;
    }
    int ans = (n + 1) * h[n] % MOD - g[n] % MOD * g[n] % MOD;
    (ans += MOD) %= MOD;
    (ans += MOD) %= MOD;
    (ans += MOD) %= MOD;
    cout << ans;
}


signed main() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (checkSubtask1()) return doSubtask1(), 0;
    
    doSubtask2();
}