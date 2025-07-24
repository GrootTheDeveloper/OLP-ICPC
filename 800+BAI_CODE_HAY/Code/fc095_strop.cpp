#include <bits/stdc++.h>
using namespace std;

int cnt1[100005], cnt2[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s1, s2; cin >> s1 >> s2;
	int n = s1.size(), m = s2.size();
	s1 = " " + s1;
	s2 = " " + s2;

	for (int i = 1; i <= n; i++)
		cnt1[i] = cnt1[i - 1] + (s1[i] == 'A'? 1 : -1);
	for (int i = 1; i <= m; i++)
		cnt2[i] = cnt2[i - 1] + (s2[i] == 'A'? 1 : -1);

	int q; cin >> q;
	while (q--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout <<  (((cnt1[b] - cnt1[a - 1]) + 300000) % 3 == (cnt2[d] - cnt2[c - 1] + 300000) % 3? "YES" : "NO");
		cout << '\n';

	}


}