#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
int f[20][20];
vector <ii> v;
int n,m;
bool cmp(ii a, ii b)
{
	double x=(double)a.se/a.fi,y=(double)b.se/b.fi;
	if (x==y) return a.fi<b.fi;
	return x>y;
}
void init()
{
	for (int i=1;i<=10;i++) for (int j=1;j<=10;j++) v.push_back(make_pair(i,j));
	sort(v.begin(),v.end(),cmp);

}

void solve()
{
	int sum=0,res=0;
	for (ii c : v)
	{
		if (m-sum>f[c.fi][c.se]*c.fi) res+=c.se*f[c.fi][c.se],sum+=f[c.fi][c.se]*c.fi;
		else
		{
			int k=(m-sum)/c.fi;
			res+=c.se*k;
			sum+=c.fi*k;
		}

	}
	cout << res;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	init();
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		int x,y;
		cin >> x >> y;
		f[x][y]++;
	}
	solve();
}