#include <bits/stdc++.h>
using namespace std;
#define sz(s) (int)s.size()

bool check(string s1, string s2)
{
	int d = 0;
	int id = 0;
	for (int i = 0; i < sz(s1); i++)
	{
		while (id < sz(s2))
		{
			if (s2[id] == s1[i]) break;
			else id++;
		}
		if (id < sz(s2)) d++, id++;
	}
	return (d == sz(s1));
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	if (n % 2 == 0) return cout << "No Solution", 0;

	int mid = n / 2;
	string s1 = s.substr(0, mid);
	string s2 = s.substr(mid + 1, mid);

	if (!check(s1, s.substr(mid, mid + 1))) s1 = "No Solution";
	if (!check(s2, s.substr(0, mid + 1))) s2 = "No Solution";

	if (s1 == s2) return cout << s1, 0;
	else
	{
		if (s1 != "No Solution" && s2 != "No Solution") return cout << "Multiple Solutions", 0;
		cout << (s1 == "No Solution"? s2 : s1);
	}
}