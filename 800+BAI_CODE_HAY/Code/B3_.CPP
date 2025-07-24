#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n;
bool check_1()
{
	int cnt = 0;
	for (int i = 1; i < n; i++)
		cnt += (a[i] == (i + 1) % n + 1);
	return cnt == n;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 1) return cout << 1, 0;
	cout << n - 1;



}