#include <bits/stdc++.h>
using namespace std;

int a[22];
int n, k;
bool us[22];
void out()
{
	for (int i = 1; i <= k; i++)
		cout << a[i] << ' ';
	cout << '\n';
}
void Try(int i)
{
	if (i > k) return out(), void();
	for (int x = a[i - 1] + 1; x <= n; x++)
	if (us[x] == false)
	{
		us[x] = true;
		a[i] = x;
		Try(i + 1);
		us[x] = false;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	Try(1);
}