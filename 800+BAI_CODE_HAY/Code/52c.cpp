#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode=1234567891;
int n,k,m,a[100005];

void sub1()
{
	unordered_map <int,int> f;
	int res=0;
	for (int i=1;i<=n;i++) 
	{
		res=(res+f[a[i]-k])%mode;
		f[a[i]]++;
	}
	cout << res;
}
unordered_map <int,vector<int>> f;
int res,node;

void Try(int val, int pos)
{
	int root=val+k;
	int t=upper_bound(f[root].begin(),f[root].end(),pos)-f[root].begin();
	if (t==(int)f[root].size()) return;
	if (root==node) return res=(res+f[root].size()-(int)t)%mode,void();
	for (int i=t;i<(int)f[root].size();i++) Try(root,f[root][i]);
}
void sub2()
{
	for (int i=1;i<=n;i++) f[a[i]].push_back(i);
	for (int i=1;i<=n-m+1;i++)
	{
		if (f[a[i]+(m-1)*k].size()) node=a[i]+(m-1)*k,Try(a[i],i);
	}
	cout << res;
}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("CMDIF.INP","r",stdin);
	freopen("CMDIF.OUT","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	if (m==2) sub1();
	else sub2();
	
}