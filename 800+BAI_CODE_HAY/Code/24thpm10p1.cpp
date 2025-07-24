#include <bits/stdc++.h>
using namespace std;
#define int long long 

int total = 0, f[30];

void add(char c)
{
	total += 2 * f[c - 'a'] + 1;
	f[c - 'a'] ++;
}
void del(char c)
{
	total -= 2 * f[c - 'a'] - 1;
	f[c - 'a'] --;	
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	string s; cin >> s;
	int l = 0, res = 0;
	for (int r = 0; r < n; r ++)
	{
		add(s[r]);
		while (total > k) del(s[l]), l++;
		//cout << l << ' ' << r << ' ' << total << '\n';
		res += (r - l) + 1;
	}
	cout << res;
}