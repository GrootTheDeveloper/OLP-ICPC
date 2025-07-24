#include <bits/stdc++.h>
using namespace std;

int a[5], n, m;
int gcd(int a, int b){
	return (b == 0? a : gcd(b, a % b));
}
void input(){
	cin >> n >> m;
}
void solve(){
	for (int i = 0; i <= 4; i++)
		a[i] = n + i;
	int ans = 1;
	int mum = 120;
	for (int i = 0; i <= 4; i++){
		int x = gcd(a[i], mum);
		mum /= x;
		a[i] /= x;
		ans = 1ll * ans * a[i] % m;
	}
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}