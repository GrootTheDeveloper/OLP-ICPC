#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;

int number_one[500005], dp[500005];
int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = res * a % mode;
		a = a * a % mode;
		b >>= 1;
	}
	return res;
}

int pos[22];
void trau(string s)
{
	int n = s.size();
	s = " " + s;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	if (s[i] == '?') pos[++cnt] = i;
	
	int ans = 0;
	int MASK = (1 << cnt) - 1;
	for (int mask = 0; mask <= MASK; mask++)
	{
		for (int i = 0; i < cnt; i++)
			if (mask >> i & 1) 
				s[pos[i + 1]] = '1';
			else 
				s[pos[i + 1]] = '0';
		int one = 0, res = 0;
		for (int i = 1; i <= n; i++)
			if (s[i] == '0')
				res += one;
			else
				one++;
		ans += res;
	}	
	cout << ans << ' ';
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int cnt_ques = 0;
	for (char c : s)
		cnt_ques += (c == '?');

	number_one[1] = 1;
	for (int i = 2; i <= cnt_ques; i++)
		number_one[i] = (number_one[i - 1] * 2 + power(2, i - 1)) % mode;
		
	s = " " + s;
	int n = s.size() - 1, one = 0, cur = 0;
	int ans = 0, CST = power(2, cnt_ques), CST_NGU = 0;
	if (cnt_ques) CST_NGU = power(2, cnt_ques - 1);
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '1')
			one++;
		if (s[i] == '0')
			ans = (ans + one * CST + number_one[cur] * power(2, cnt_ques - cur)) % mode;
		if (s[i] == '?')
			ans = (ans + one * CST_NGU + number_one[cur] * power(2, cnt_ques - cur - 1)) % mode, cur++;
	}
	cout << ans;


}