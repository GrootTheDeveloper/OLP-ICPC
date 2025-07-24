#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[111];
signed main()
{
	freopen("nlargest.inp","r",stdin);
	freopen("nlargest.out","w",stdout);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int pos = 0;
	for (int i = n - 1; i >= 1; i--)
		if (a[i] != a[i + 1])
		{
			pos = i;
			break;
		}
	cout << a[pos];
}