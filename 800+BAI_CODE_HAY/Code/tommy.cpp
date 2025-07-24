#include <bits/stdc++.h>
using namespace std;
//#define int long long 

bool prime[10000001];
int long_set=0,n,m;
int set_p[700000],f[700000],cnt[10000001];
void sie2(int lim)
{
	for (int i=2;i<=lim;i++) 
		if (!prime[i]) 
		{
			long_set++;
			f[long_set]=f[long_set-1];
			set_p[long_set]=i;
			f[long_set]+=cnt[i];
			for (int j=i*2;j<=lim;j+=i) prime[j]=true,f[long_set]+=cnt[j];
		}
}
int ai;
signed main()
{
	freopen("t.inp","r",stdin);
	cin >> n;
	int MAX=0;
	for (int i=1;i<=n;i++) cin >> ai,cnt[ai]++,MAX=max(MAX,ai);
	sie2(MAX);
	cin >> m;
	int l,r;
	while (m--)
	{
		cin >> l >> r;
		int pos_last=upper_bound(set_p+1,set_p+long_set+1,r)-set_p-1,
			pos_firt=lower_bound(set_p+1,set_p+long_set+1,l)-set_p;
		cout << f[pos_last]-f[pos_firt-1] << '\n';
	}


	cout << clock()/(double)1000 << " s";
}