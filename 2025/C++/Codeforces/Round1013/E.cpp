#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXP = 10000005;
vector<int> checkPrime(MAXP, true);
vector<int> prime;

void sieve() {
    checkPrime[0] = checkPrime[1] = false;
    for (int i = 2; i < MAXP; i++) {
        if (checkPrime[i]) {
            for (int j = i * i; j < MAXP; j += i) {
                checkPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < MAXP; i++) {
        if(checkPrime[i]) prime.push_back(i);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int l = 0, r = prime.size() - 1;
            int need = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (prime[mid] * i <= n) {
                    need = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            ans += need + 1;
        }
        cout << ans << endl;
    }
    return 0;
}