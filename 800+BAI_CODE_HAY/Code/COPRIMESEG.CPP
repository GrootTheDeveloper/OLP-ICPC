#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int LOG = 17;
long long a[N], st[N][LOG];
int n, lg[N];
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
long long gcd(long long a, long long b){
	if (b == 0) 
		return a;
	return gcd(b, a % b);
}
void init(){
	for (int i = 1; i <= n; i++)
		st[i][0] = a[i];
	for (int step = 1; (1 << step) <= n; step++)
		for (int i = 1; i + (1 << step) - 1 <= n; i++)
			st[i][step] = gcd(st[i][step - 1], st[i + (1 << (step - 1))][step - 1]);
	lg[1] = 0;
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i / 2] + 1;
}

long long get(int l, int r){
	int step = lg[r - l + 1];
	return gcd(st[l][step], st[r - (1 << step) + 1][step]);
}
bool check(int len){
	for (int i = 1; i + len - 1 <= n; i++)
		if (get(i, i + len - 1) == 1)
			return true;
	return false;
}
void solve(){
	int l = 1, r = n, ans = -1;
	while (l <= r){
		int mid = (l + r) >> 1;
		if (check(mid)) 
			ans = mid, r = mid -1;
		else
			l = mid + 1;
	}
	cout << ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	init();
	solve();
}