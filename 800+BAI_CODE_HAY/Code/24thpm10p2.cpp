#include <bits/stdc++.h>
using namespace std;
#define int long long 

int cnt[1000006], d[1000006], sum[1000006];
int lim, siz;

void init()
{
	for (int i = 1, total; i <= lim; i++)
	{
		total = 0;
		for (int j = i; j <= lim; j += i)
			total += cnt[j];
		if (total)
		{
			d[++siz] = i;
			sum[siz] = sum[siz - 1] + total;
		}
	}
}		


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,q; cin >> n >> q;
	for (int i = 1, ai; i <= n; i ++) cin >> ai, lim = max(lim, ai), cnt[ai] ++;
	init();
	for (int i = 1, p; i <= q; i++)
	{
		cin >> p;
		int pos = upper_bound(sum + 1, sum + siz + 1, p) - sum - 1;
		cout << ((sum[pos] == p) ? d[pos] : d[pos + 1]) << ' ';
	}

}