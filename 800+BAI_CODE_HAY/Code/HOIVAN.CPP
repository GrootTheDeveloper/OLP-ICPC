#include <bits/stdc++.h>
using namespace std;
mt19937_64 rd(time(NULL));
long long l, r, pow10[10];
void input(){
	cin >> l >> r;
}

int contribute(int n){	
	int len = 0, tmp = n, rever = 0;
	while (tmp) rever = rever * 10 + tmp % 10, tmp /= 10, ++len;
	int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		long long val = 1ll * (n * 10 + i) * pow10[len] + rever;
		ans += (val >= l && val <= r);
	}

	long long omg = 1ll * n * pow10[len] + rever;
	return ans + (omg >= l && omg <= r);

}
int solve(){
	pow10[1] = 10;
	for (int i = 2; i <= 8; i++)
		pow10[i] = pow10[i - 1] * 10;
	int ans = 0;
	for (int x = 1; x <= 1e7; x++)
		ans += contribute(x);
	return ans;
}
int Rand(int L, int R){
	return L + rd() % (R - L + 1);
}
void gen(){
	l = Rand(1, 1e2);
	r = Rand(l, 1e5);
}
bool check(int n){
	string s = to_string(n);
	int l = 0, r = s.size() - 1;
	while (s[l] == s[r] && l <= r)
		r--, l++;
	return r < l;
}
int buff(){
	int ans = 0;
	for (int i = l; i <= r; i++)
		ans += check(i);
	return ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	cout << solve();

	// l = 10001, r = 10001;
	// cout << solve() << ' ' << buff();
	// int T = 50;
	// while (T--)
	// {
	// 	gen();
	// 	cout << l << ' ' << r << '\n';
	// 	int A = solve(), B = buff();
	// 	cout << A << ' ' << B << "    " << (A == B? "ACCEPTED" : "WRONG") << endl;
	// }
}