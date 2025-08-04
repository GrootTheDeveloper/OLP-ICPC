#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MAXN = 2e6;
vector<int> divisors(MAXN + 5, 0);

void freak(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors[i]++;
            if (n / i != i) {
                divisors[n / i]++;
            }
        }
    }
}
signed main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        freak(a[i]);
    }

    int ans = 0;

    for (int i = 1; i <= MAXN; i++) {
        ans = max(ans, (divisors[i] > 1 ? divisors[i] : 0) * i);
    }
    cout << ans;

}