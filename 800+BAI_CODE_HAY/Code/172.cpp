#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int base = 311, mode = 1e9 + 7, MODE = mode * mode;
string s;
int n;
int T[2000006], p[2000006];
int get(int l, int r)
{
	return (T[r] - T[l - 1] * p[r - l + 1] + MODE) % mode;
}
bool check(int a, int b, int mid)
{
	return get(a, a + mid) != get(b, b + mid);
}

bool larg(int a, int b)
{
	int l = 0, r = n - 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(a, b, mid)) r = mid - 1;
		else l = mid + 1;
	}
	while (check(a, b, l - 1) && l > 0) l--;
	while (!check(a, b, l) && l < n - 1) l++;
	return s[b + l] < s[a + l];
}
void solve()
{
	s = " " + s + s;
	p[0] = 1;
	for (int i = 1; i <= n * 2; i++)
	{
		p[i] = p[i - 1] * base % mode;
		T[i] = (T[i - 1] * base + s[i] - 'a' + 1) % mode;
	}
	
	int pos = 1;
	for (int i = 2; i <= n + 1; i++)
		if (larg(pos, i)) pos = i;
	for (int i = pos; i <= pos + n - 1; i++) cout << s[i];
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	n = s.size();
	solve();
}