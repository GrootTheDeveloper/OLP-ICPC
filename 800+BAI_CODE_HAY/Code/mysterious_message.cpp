#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define TASK "mysterious"

signed main()
{
	freopen(TASK".INP","r",stdin);
	freopen(TASK".OUT","w",stdout);
	cout << (int)'z' << ' ' << (int)'Z';
	string s; cin >> s;
	int n = s.size();
	s = " " + s;
	for (int i = 1; i <= n - 1; i += 2)
	{
		int val = (s[i] - '0') * 10 + (s[i + 1] - '0');
		cout << (char)val;
	}
}