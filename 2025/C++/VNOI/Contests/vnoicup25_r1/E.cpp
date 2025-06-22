#include <bits/stdc++.h>
#define int long long
using namespace std;

const int SIZE = pow(2,20) + 1;
const int mod = 998244353;
int n, k; 
vector<int> fact(SIZE, 1), inv_fact(SIZE, 1);
int qpow(int n, int k, int MOD = mod) {
    if (k == 1) return n;
    if (k == 0) return 1;
    int temp = qpow(n, k / 2);
    temp = temp * temp % MOD;
    if (k % 2 == 1) {
        temp *= n;
    }
    temp %= MOD;
    return temp;
}

int C(int n, int k){
    return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < SIZE; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv_fact[i] = qpow(fact[i], mod - 2);
    }
    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        int cnt1 = 0, cnt0 = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) cnt0++;
            else cnt1++;
        }
        if (cnt1 == n) {
            int ans = fact[n] * n;
            ans %= mod;
            cout << ans;
        }
        else if (cnt0 == n) {
            cout << 0;
        }
        else {
            // sắp xếp i phần tử 1 vào đầu: C(cnt1, i) * i!
            // ans = C(cnt1, i) * i! * cnt0 * (n - i - 1)! * i
            int ans = 0;
            for (int i = 1; i <= cnt1; i++) {
                int temp = C(cnt1, i) * fact[i] % mod;
                temp = temp * cnt0 % mod;
                temp = temp * fact[n-i-1] % mod;
                temp = temp * i % mod;
                ans = (ans + temp) % mod;
            }
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}