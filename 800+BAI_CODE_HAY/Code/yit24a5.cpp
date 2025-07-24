#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int l,r;
int cnt1[256],cnt2[256];

struct dta{
	int fi;
	char se;
}a[10000];


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> s;
	cin >> l >> r;
	int k=0,n=0;
	for (char c : s)
	{
		if ('A'<=c && c <='Z') 
		{
			n++;
			a[n].fi=k;
			a[n].se=c;
			k=0;
		}
		else k=k*10+(c-'0');
	}
	int sum=0;
	l--;
	for (int i=1;i<=n;i++)
	{
		if (l-sum>a[i].fi) cnt1[(int)a[i].se]+=a[i].fi;
		else if (l-sum>0) cnt1[(int)a[i].se]+=l-sum;
		if (r-sum>a[i].fi) cnt2[(int)a[i].se]+=a[i].fi;
		else if (r-sum>0) cnt2[(int)a[i].se]+=r-sum;
		sum+=a[i].fi;
	}
	int res=0;
	for (char c='A';c<='Z';c++) 
		res=max(res,cnt2[(int)c]-cnt1[(int)c]);
	cout << res;
	
}