#include <bits/stdc++.h>
using namespace std;
#define int long long
int divs[1000006];
bool prime[10005];
void init()
{
	for (int i=2;i<=1e6;i++)
		if (!divs[i]) for (int j=i;j<=1e6;j+=i) divs[j]=i;
	prime[0]=prime[1]=true;
	for (int i=2;i<=100;i++) if (!prime[i])
		for (int j=i*i;j<=10000;j+=i) prime[j]=true;

}

int cnt[1000006];
bool check(int n)
{
	int cntdivs=1;
	while (n!=1)
	{
		int k=divs[n],t=0;
		while (n%k==0) t++,n/=k;
		cntdivs*=(t*2+1);

	}
	return (!prime[cntdivs]);
	
}
main()
{
	//freopen("BAI4.INP","r",stdin);
	//freopen("BAI4.OUT","w",stdout);
	int l,r; cin >> l >> r;
	
	init();
	int x=(int)sqrt(l),y=(int)sqrt(r);
	int res=0;
	if (x*x<l) x++;
	for (int i=x;i<=y;i++)
		res+=check(i);
	cout << res;
	//cout << '\n' << clock()/(double)1000;

}