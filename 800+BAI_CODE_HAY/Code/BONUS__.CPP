#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 111539768;
int m, n, k, x, y, u, v;

int mul(int a, int b){
	return (__int128)a * (__int128)b % mode;
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
int sum(int n, int x){
	if (n == 0)
		return 0;
	if (n == 1)
		return x;
	int sub = sum(n / 2, x);
	if (n & 1)
		return (sub + mul((1 + sub), power(x, n / 2 + 1))) % mode;
	else
		return (sub + mul(sub, power(x, n / 2))) % mode;
}
void input(){
	cin >> m >> n >> k >> x >> y >> u >> v;
}
void solve(){
	int cur_value = power(k, (x - 1) * n + y - 1);
	int sum_row   = mul(cur_value, (1 + sum(v - y, k)));
	int q = power(k, n);
	cout << mul(sum_row, (1 + sum(u - x, q)));

	//cout << cur_value << ' ' << sum_row;

}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}