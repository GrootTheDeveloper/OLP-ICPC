#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2*1e6;

vector<int> prime(MAXN + 5, true);
vector<int> primeNum;
void sang() {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= MAXN; i++) {
        if (prime[i]) {
            for (int j = i*i; j <= MAXN; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAXN; i++) {
        if (prime[i]) primeNum.push_back(i);
    }
}

signed main() {
    sang();
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        int ans = 1;
        for (int p : primeNum) {
            if (p * p > n) break;
            int cnt = 0;
            if (n % p == 0) {
                while (n % p == 0) {
                    n/=p;
                    cnt++;
                }
            }
            ans *= (cnt + 1);
        }
        if (n > 1) ans *= 2;
        cout << ans << endl;
    }
}
