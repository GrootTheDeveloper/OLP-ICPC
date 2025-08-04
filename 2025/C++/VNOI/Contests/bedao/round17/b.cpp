#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MAXN = 1e6;
vector<int> prime;
vector<bool> isPrime(MAXN + 5, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= MAXN; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAXN; i++) {
        if (isPrime[i]) prime.push_back(i);
    }
}
signed main() {
    sieve();
    int n; cin >> n;
    int sz = prime.size();
    int ans = 0;
    vector<int> a(sz);
    for (int i = 0; i < sz; i++) {
        a[i] = prime[i] * prime[i] * prime[i];
    }

    for (int i = 0; i < sz; i++) {
        int j = i + 1;
        int cnt = 0;
        while (j < sz) {
            if (a[j] <= n / a[i]) {
                cnt++;
//                cout << a[j] << " " << a[i ] << endl;
                j++;
            }
            else {break;}
        }
        ans += cnt;
    }
    cout << ans;
}