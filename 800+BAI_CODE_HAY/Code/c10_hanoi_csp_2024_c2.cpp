#include <bits/stdc++.h>
using namespace std;
#define int long long 

bool mark[11];
bool isDigit(int n)
{
	while (!mark[n % 10] && n > 0) n /= 10;
	return n == 0;
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
		mark[s[i] - '0'] = true;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += isDigit(i);
	cout << ans;
}