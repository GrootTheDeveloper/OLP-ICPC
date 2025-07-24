#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[3000], cnt[3000];

bool check()
{
	for (char c = 'a'; c <= 'z'; c++)
		if (cnt[(int)c] != f[(int)c]) return false;
	for (char c = 'A'; c <= 'Z'; c++)
		if (cnt[(int)c] != f[(int)c]) return false;
	return true;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	string s1, s2; cin >> s1 >> s2;
	for (char c : s1) cnt[(int)c]++;
	
	int ans = 0;
	s2 = " " + s2;
	for (int i = 0; i <= m; i++)
	{
		f[(int)s2[i]]++;
		if (i >= n)
		{
			f[(int)s2[i - n]]--;
			ans += check();
		}
	}
	cout << ans;
	//
}