#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long qpow(long long n, long long base) {
	if (base == 0) return 1;
	long long temp = qpow(n, base / 2);
	temp %= mod;
	if (base % 2 == 0) {
		return temp * temp % mod;
	}
	return temp * temp % mod * n % mod;
}

int main() {

	int n; cin >> n;
	int k; cin >> k;
	vector<int>a(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a.begin() + 1, a.end());
	vector<long long>fact(1e5 + 5, 1), inv_fact(1e5 + 5, 1);
	for (int i = 1; i <= n; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}
	for (int i = 1; i <= n; i++) {
		inv_fact[i] = qpow(fact[i], mod - 2);
		inv_fact[i] %= mod;
	}
	// 5 6 6 7
	// Bat dau tu so thu k, ta co the chon k - 1 so truoc no de ghep vao

	long long res = 0;
	auto get = [&](int n, int k) -> long long {
		return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
		};


	for (int i = k; i <= n; i++) {
		res += a[i] * get(i - 1, k - 1);
		res %= mod;
	}
	cout << res;
}
