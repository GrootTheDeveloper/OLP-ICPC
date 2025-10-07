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
        for (int p : primeNum) {
            if (p * p > n) break;
            if (n % p == 0) {
                cout << p << " ";
                while (n % p == 0) {
                    n/=p;
                }
            }
        }
        if (n > 1) cout << n;
        cout << endl;
    }
}
