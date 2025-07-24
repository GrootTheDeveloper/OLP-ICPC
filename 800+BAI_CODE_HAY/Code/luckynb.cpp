#include <bits/stdc++.h>
using namespace std;
#define int long long 

bool prime[1000006];
int  cnt[1000006], d[1000006];
void init(int lim)
{
	for (int i = 1; i <= lim; i++) d[i] = 1;
	for (int i = 2; i * i <= lim; i++)
		if (!prime[i]) for (int j = i * i; j <= lim; j += i) prime[j] = true;
	for (int i = 2; i <= lim; i++)
		if (!prime[i]) for (int j = i; j <= lim; j += i) d[j] *= i;
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, a, b; cin >> n >> a >> b;
	init(n);
	int res = 0;
	for (int i = a; i <= b; i++)
		cnt[d[i]]++, res = max(res, cnt[d[i]]);
	cout << res;
}