#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
struct dta{ int x,y;};
dta a[1111];
bool cmp(dta a, dta b)
{
	if (a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("PTSET.INP","r",stdin);
	freopen("PTSET.OUT","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> a[i].x >> a[i].y;
	sort(a+1,a+n+1,cmp);
	int p,q,pos,res=0;
	for (int i=1;i<n;i++)
	for (int j=i+1;j<=n;j++)
	{
		int cnt=0;
		int h=a[j].x-a[i].x,k=a[j].y-a[i].y;
		for (int l=j+1;l<=n;l++)
		{
			if (h==0 && k!=0)
			{
				if ((a[l].y-a[i].y)%k==0) cnt++;
			}
			else if (h!=0 && k==0)
			{
				if ((a[l].x-a[i].x)%h==0) cnt++;
			}
			else if ((a[l].x-a[i].x)/h==(a[l].y-a[i].y)/k) cnt++;
		}
		if (cnt>res) res=cnt,pos=i,p=h,q=k;
	}

	vector <dta> vi;
	vi.push_back(a[pos]);
	res=1;
	for (int i=pos+1;i<=n;i++)
	{
		if (p==0 && q!=0)
			{
				if ((a[i].y-a[pos].y)%q==0) res++,vi.push_back(a[i]);
			}
			else if (p!=0 && q==0)
			{
				if ((a[i].x-a[pos].x)%p==0) res++,vi.push_back(a[i]);
			}
			else if ((a[i].x-a[pos].x)/p==(a[i].y-a[pos].y)/q) res++,vi.push_back(a[i]);
	}
	cout << res << endl;
	for (dta c : vi) cout << c.x << ' ' << c.y << '\n';
}
