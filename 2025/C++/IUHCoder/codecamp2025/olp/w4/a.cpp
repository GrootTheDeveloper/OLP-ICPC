#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MAXN = 2e6;
vector<int> divisors(MAXN + 5, 0);

void fuck(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors[i]++;
            if (i != n / i) {
                divisors[n / i]++;
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fuck(a[i]);
    }
    int ans = 0;

    for (int i = 1; i <= MAXN; i++) {
        if (divisors[i] > 1) {
            ans = max(ans, divisors[i] * i);
        }
    }
    cout << ans;
    
}