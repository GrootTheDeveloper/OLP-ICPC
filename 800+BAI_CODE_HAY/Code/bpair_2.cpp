#include <bits/stdc++.h>
using namespace std;
#define int long long 
int val[1000006], cnt[1000006];
bool prime[1000006];

void sie(int lim)
{
	for (int i = 2; i * i <= lim; i++)
		if (!prime[i]) for (int j = i * i; j <= lim; j += i) prime[j] = true;
	
	for (int i = 1; i <= lim; i++) val[i] = 1;
	for (int i = 2; i <= lim; i++)
		if (!prime[i]) for (int j = i; j <= lim; j += i) val[j] *= i;

}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int l, r; cin >> l >> r;
	sie(r);
	int res = 0;
	for (int i = l; i <= r; i++)
	{
		res += cnt[val[i]];
		cnt[val[i]]++;
	}
	cout << res;
}