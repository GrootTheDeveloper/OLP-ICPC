#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for (string s; t; --t)
	{
		int n; cin >> n;
		n -= 1;
		cin >> s;
		string st = "", res = "NO";
		for (int i = 0; i < 4; i++)
		{
			st.push_back(s[i]);
			string l = st;
			for (int j = n - 4 + i + 2; j <= n; j++) l.push_back(s[j]);
			if (l == "2020") res = "YES";	
		}
		if (s[n] == '0' && s[n-1] == '2' && s[n-2] == '0' && s[n-3] == '2') res = "YES";
		cout << res << '\n';
	}
}