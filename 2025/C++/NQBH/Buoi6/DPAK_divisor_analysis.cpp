#include <bits/stdc++.h>
#define int long long
using namespace std;
int N = 1e6;
const int mod = 1e9 + 7;

struct divisor{
    int prime;
    int power;
};

int qpow(int n, int k, int MOD = mod) {
    if (k == 0) return 1;
    if (k == 1) return n;
    int temp = qpow(n, k / 2) % MOD;
    temp *= temp % MOD;
    if (k % 2 == 1) {
        (temp *= n) %= MOD;
    }
    return temp;
}
signed main(){
    int n; cin >> n;
    vector<divisor> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].prime >> a[i].power;
    }

    int numDivisor = 1;
    int sumDivisor = 1;
    int total = 1;
    for (int i = 0; i < n; i++) {
        (numDivisor *= a[i].power + 1) %= mod; 
        (sumDivisor *= ((qpow(a[i].prime, a[i].power + 1) - 1) / (a[i].prime - 1)) > 0 ?(qpow(a[i].prime, a[i].power + 1) - 1) / (a[i].prime - 1):1 ) %= mod;
        (total *= qpow(a[i].prime, a[i].power)) %= mod;
    }
    int productDivisor = qpow(total, numDivisor / 2, mod - 1) % mod;
    cout << numDivisor << endl << sumDivisor << endl << productDivisor;
    return 0;
}