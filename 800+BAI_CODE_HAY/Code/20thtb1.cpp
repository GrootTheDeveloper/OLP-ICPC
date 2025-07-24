#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7; 
int lim = 0;
int p[10000001], a[100005];
int larg[10000007];
vector <int> prim;

void make_list()
{
	for (int i = 2; i <= lim; i++)
		if (!p[i])
		{
			prim.push_back(i);
			for (int j = i; j <= lim; j += i) p[j] = i;
		}
}

void proc(int &n)
{
	while (n != 1)
	{
		int k = p[n], cnt = 0;
		while (k == p[n]) cnt ++, n/= k;
		larg[k] = max(larg[k], cnt);
	}
}
int fastpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b&1) res = res * a % mode;
		a = a * a % mode;
		b /= 2;
	}
	return res;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], lim = max(lim, a[i]);
	make_list();
	for (int i = 1; i <= n; i++) proc(a[i]);
	int res = 1;
	for (int x : prim)
	{
		if (larg[x] & 1) larg[x] ++;
		res = res * fastpow(x, larg[x]) % mode;
	}
	cout << res;

}