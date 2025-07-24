#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; getline(cin, s);
	s = s + "a";
	string st = "";
	for (char c : s)
	{
		if ((c >= '0' && c <= '9') || c == '-') st.push_back(c);
		else if (st.size())
		{
			cout << st << ' ';
			st = "";
		}
	}
}