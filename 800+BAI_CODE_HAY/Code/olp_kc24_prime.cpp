#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define sz(s) (int)s.size()


vector<int> p;
bool prime[1000006];
void init()
{
	for (int i = 2; i <= 1e6; i++)
	if (!prime[i]) for (int j = i * i; j <= 1e6; j+=i) prime[j] = true;
	
	for (int i = 2; i <= 1e6; ++i)
	if (!prime[i]) p.push_back(i);
}

int lim = 0;
int op[1000][5];

void extract(int n)
{
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	if (n % ((i + 1) * (j + 1)) == 0 && (i + 1) * (j + 1) != n)
	{
		lim++;
		op[lim][0] = i;
		op[lim][1] = j;
		op[lim][2] = n / ((i + 1) * (j + 1)) - 1;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	init();
	extract(k);

	int ans = 0;

	for (int i = 0; i < sz(p) - 2; i++)
	{
		//if (p[i] * p[i] * p[i] > n) break;
		for (int id = 1; id <= lim; id++)
		{
			int m = 1;
			bool ok = true;
			for (int j = 1; j <= op[id][0]; j++)
				if (n / m >= p[i]) 
					m *= p[i];
				else {ok = false; break;}

			for (int j = 1; j <= op[id][1]; j++)
				if (n / m >= p[i + 1]) 
					m *= p[i + 1];
				else {ok = false; break;}

			for (int j = 1; j <= op[id][2]; j++)
				if (n / m >= p[i + 2]) 
					m *= p[i + 2];
				else {ok = false; break;}
			if (ok) ans = max(ans, m);
		}
	}	
	cout << ans;

}