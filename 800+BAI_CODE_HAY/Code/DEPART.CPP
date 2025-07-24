#include <bits/stdc++.h>
using namespace std;
const int base = 311, mode = 1e9 + 7;
int n;
string X;
string a[10004];
int p[100005], T[100005];
unordered_map<int,bool> f;
int dp[100005];
bool isCnt(string s)
{
	for (int i = 1; i <= n; i++)
	if (s == a[i]) return true;
	return false;
}
void sub1()
{
	X = " " + X;
	int m = X.size() - 1;
	dp[0] = 1;
	for (int i = 1; i <= m; i++)
	{
		dp[i] = 0;
		for (int j = i; j >= max(1, i - 99); j--)
		if (isCnt(X.substr(j, i - j + 1))) dp[i] = dp[i] + dp[j - 1];
	}
	cout << dp[m];
}

int gethash(int l, int r)
{
	return (1ll * T[r] - 1ll * T[l - 1] * p[r - l + 1] % mode + mode) % mode;
}
int Hash(string s)
{
	int ans = 0;
	for (char c : s)
		ans = (1ll * ans * base + c) % mode;
	return ans;
}
void sub2()
{
	int lim  = 0;
	for (int i = 1; i <= n; i++)
		f[Hash(a[i])] = true, lim = max(lim, (int)a[i].size());

	int m = X.size() - 1;
	p[0] = 1;
	for (int i = 1; i <= m; i++)
	{
		p[i] =  1ll * p[i - 1] * base % mode;
		T[i] = (1ll * T[i - 1] * base + X[i]) % mode;
	}
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= m; i++)
	for (int j = i; j >= max(1, i - lim + 1); j--)
	if (f.find(gethash(j, i)) != f.end()) 
		dp[i] = dp[j - 1] + dp[i];	
	cout << dp[m];
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("DEPART.inp","r",stdin);
	freopen("DEPART.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> X;
	if (n <= 100) sub1();
	else sub2();
}