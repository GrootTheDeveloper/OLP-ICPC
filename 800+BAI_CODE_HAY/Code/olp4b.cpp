#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool use[100005];
int w[100005],v[100005],f[100005];

struct dta
{
	int wi,ci;
};
dta pus;
vector <dta> vi;
vector <dta> kho;
bool cmp(dta a, dta b)
{
	return a.wi<b.wi;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,s; cin >> n >> s;
	int sum=0,val=0;
	for (int i=1;i<=n;i++)
	{
		cin >> w[i] >> v[i] >> use[i];
		pus.wi=w[i];
		pus.ci=v[i];
		if (use[i])
		{
			sum+=w[i];val+=v[i];
			kho.push_back(pus);
		}
		else vi.push_back(pus);
	}

	sort(vi.begin(),vi.end(),cmp);
	
	int lim=vi.size(),res=val;
	for (int i=1;i<=vi.size();i++)
	{
		f[i]=max(f[i-1],vi[i-1].ci);
		w[i]=vi[i-1].wi;
	}
	
	for (dta p : kho)
	{
		int pos=upper_bound(w+1,w+lim+1,s-(sum-p.wi))-w-1;
		res=max(res,val-p.ci+f[pos]);
	}
	cout << res;
	

}