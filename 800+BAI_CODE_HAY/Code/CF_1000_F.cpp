#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ii pair<int,int>
#define iii pair<ii, int>
#define fi first
#define id second
#define l first
#define r second
const int N = 5e5 + 5;


int S;
int a[N], ans[N];
iii Q[N];
bool cmp(iii a, iii b)
{
	if (a.fi.l / S != b.fi.l / S)
		return a.fi.l / S < b.fi.l / S;
	if ((a.fi.l/S) & 1)
		return a.fi.r < b.fi.r;
	return a.fi.r > b.fi.r;
}
bool mark[N];
int cnt[N], bl[1000], good;
void add(int val)
{
	++cnt[val];
	if (cnt[val] == 1)
	{
		bl[val / S]++;
		mark[val] = true;
		++good;
	}
	else if (cnt[val] == 2)
	{
		bl[val / S]--;
		mark[val] = false;
		--good;
	}
}
void del(int val)
{
	--cnt[val];
	if (cnt[val] == 1)
	{
		bl[val / S]++;
		mark[val] = true;
		++good;
	}
	else if (cnt[val] == 0)
	{
		bl[val / S]--;
		mark[val] = false;
		--good;
	}
}

int get()
{
	if (good == 0) return 0;
	for (int i = 0; i <= S; i++)
		if (bl[i])
		{
			for (int j = i * S;;j++)
				if (mark[j]) return j;
		}
	return 0 + 0 + 0;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		cin >> Q[i].fi.l >> Q[i].fi.r;
		Q[i].id = i;
	}
	S = (int)sqrt(q);
	sort(Q + 1, Q + q + 1, cmp);
	int l = 1, r = 0;
	for (int i = 1; i <= q; i++)
	{
		while (Q[i].fi.r > r) add(a[++r]);
		while (Q[i].fi.r < r) del(a[r--]);
		while (Q[i].fi.l > l) del(a[l++]);
		while (Q[i].fi.l < l) add(a[--l]);
		ans[Q[i].id] = get();
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}