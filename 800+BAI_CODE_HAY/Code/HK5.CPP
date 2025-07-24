#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int mode = 1e15 + 7;
ii a[100005];
int n;
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].fi;
	for (int i = 1; i <= n; i++)
		cin >> a[i].se;
	sort(a + 1, a + n + 1, [](ii &x, ii &y){
		return (double)x.fi / x.se < (double)y.fi / y.se;
	});
}
int gcd(int a, int b){
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int mul(int a, int b){
	int res = 0;
	while (b){
		if (b & 1)
			res = (res + a) % mode;
		a = (a + a) % mode;
		b >>= 1;
	}
	return res;
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
void solve(){
	int p = a[1].fi * a[n].se + a[n].fi * a[1].se;
	int q = a[1].se * a[n].se;
	int x = gcd(p, q);
	p /= x;
	q /= x;
	cout << power(p, q);
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}