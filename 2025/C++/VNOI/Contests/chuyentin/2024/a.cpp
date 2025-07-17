#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
int m, n, k;
vector<vector<int>> a;
vector<int> fact(MAXN + 1, 1), inv_fact(MAXN + 1, 1);

int qpow(int base, int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    int temp = qpow(base, exp / 2);
    temp = temp % MOD * temp % MOD;
    if (exp % 2 == 1) {
        return temp * base % MOD;
    }
    return temp;
}
int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return int(1LL * fact[n] * inv_fact[k] % MOD * inv_fact[n-k] % MOD);
}
void init() {
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[MAXN] = qpow(fact[MAXN], MOD-2);
    for (int i = MAXN; i > 0; i--) {
        inv_fact[i-1] = int(inv_fact[i] * i % MOD);
    }
}

void subtask1() {

}

void subtask2() { 

}

void subtask3() {
    init();
}


void subtask4() {

}
void subtask5() {
    
}

signed main() {
    cin >> m >> n >> k;
    a.resize(m + 1, vector<int>(m + 1, 0));
    for (int t = 1; t <= k; t++) {
        int x, y; cin >> x >> y;
        a[x][y] = -1;
    }    
    if (m <= 10 && n <= 10 && k == 0) return subtask1(), 0;
    if (m <= 1000 && n <= 1000) return subtask2(), 0;
    if (k == 0) return subtask3(), 0;
    if (k <= 5) return subtask4(), 0;
    return subtask5(), 0;
}