#include <bits/stdc++.h>
using namespace std;
#define int long long 

int cnt[30];
signed main()
{
	string s; cin >> s;
	for (char c : s) cnt[c - 'A']++;
	int res = INT_MAX;
	string st = "CORONA";
	for (char c : st)
	{
		if (c != 'O')
			res = min(res, cnt[c - 'A']);
		else 
			res = min(res, cnt[c - 'A'] / 2);
	}
	cout << res;
}