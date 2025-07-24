#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;
string s;
int x[100005],y[100005],n;
int calc(int n)
{
	return n * (n + 1) * (2 * n +1) / 6;
}
int sum(int n)
{
	return n * (n + 1) / 2;
}
void sub1()
{
	int res = 0;
	for (int i = 1; i <= n; i++) for(int j = i; j <= n; j++)
	{
		if (x[j] - x[i -1] == 0) res = (res + (y[j] - y[i -1])*(y[j] - y[i -1]));// % mode;
		else if (y[j] - y[i -1] == 0) res = (res + (x[j] - x[i -1])*(x[j] - x[i -1]));// % mode;
		else res = (res + (x[j] - x[i - 1]) * (y[j] - y[i - 1]));// % mode;
	}
	cout << res;
}
void sub2()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += calc(n - i + 1);
	cout << res;
}
void sub3()
{
	int pos = 0;
	for (int i = 1; i < n; i++) if (s[i] != s[i - 1]) pos = i;
	int res = 0;
	
	for (int i = 1; i <= n; i++)
	{
		if (i <= pos)
			res += calc(pos - i + 1) + (pos - i + 1) * sum(n - pos);
		else res += calc(n - i +1); 
	}
	cout << res;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; i++)
	{
		x[i] = x[i - 1] + (s[i - 1] == '1');
		y[i] = y[i - 1] + (s[i - 1] == '0');
	}
	if (s.size() <= 5000) sub1();
	else if (x[n] == n || y[n] == n) sub2();
	else sub3();
	
	

}