#include <bits/stdc++.h>
using namespace std;

signed main()
{
	string s;; cin >> s;
	s.push_back(':');
	string st = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ':') st.push_back(s[i]);
		else 
		{
			cout << "0x" + st;
			cout << (i != s.size() - 1? ", ": "");
			st = "";
		}
	}
}