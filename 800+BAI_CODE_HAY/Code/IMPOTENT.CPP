#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
int a, b, gt[2000007];
void input(){
	cin >> a >> b;
}
int power(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = 1ll * res * a % mode;
		a = 1ll * a * a % mode;
		b >>= 1;
	}
	return res;
}
int C(int n, int k){
	if (k > n)
		return 0;
	return 1ll * gt[n] * power(1ll * gt[k] * gt[n - k] % mode, mode - 2) % mode;

}
void solve(){
	if (a + b == 0)
		return cout << "IMPOTENT", void();
	gt[0] = 1;
	for (int i = 1; i <= 2e6 + 5; i++)
		gt[i] = 1ll * gt[i - 1] * i % mode;
 	int ans = 1ll * gt[a] * gt[b] % mode;
 	ans = 1ll * C(b + 1, a) * ans % mode;	
 	if (ans)
 		cout << ans;
 	else
 		cout << "IMPOTENT";
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}