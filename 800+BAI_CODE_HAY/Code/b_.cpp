#include <bits/stdc++.h>
using namespace std;

bool prime[5000006];

void sie()
{
	prime[0] = prime[1] = true;
	for (int i = 2; i * i <= 5e6; i++)
	if (!prime[i]) for (int j = i * i; j <= 5e6; j += i) prime[j] = true;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	sie();
	string st = "";
	s.push_back('a');
	int cnt = 0, p = 0;
	for (char c : s)
	{
		if (isdigit(c))
		{
			st.push_back(c);
			cnt++;
		}else if (st.size())
		{
			int k = stoi(st);
			if (!prime[k]) p = max(p, k);
			st = "";
		}
	}
	cout << cnt << '\n' << p;
}