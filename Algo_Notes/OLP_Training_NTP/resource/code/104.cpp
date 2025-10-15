#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2*1e6;

vector<int> prime(MAXN + 5, true);

void sang() {
    prime[0] = prime[1] = false;
    for (int i = 2; i <= MAXN; i++) {
        if (prime[i]) {
            for (int j = 2*i; j <= MAXN; j += i) {
                prime[j] = false;
            }
        }
    }
}

signed main() {
    sang();
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) cout << i << " ";
    }
}