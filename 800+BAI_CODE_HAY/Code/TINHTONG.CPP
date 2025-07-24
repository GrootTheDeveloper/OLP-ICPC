#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, x;
void input(){
	cin >> x >> n >> m;
}
int mul(int a, int b){
	return (__int128)a * (__int128)b % m;
}
int power(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}
int sum(int n){
	if (n == 1)
		return x;
	int sub = sum(n / 2);
	if (n & 1ll)
		return (sub + mul(power(x, n / 2 + 1), 1 + sub)) % m;
	else
		return (sub + mul(power(x, n / 2), sub)) % m;
}
void solve(){
	cout << (1 + sum(n)) % m;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}