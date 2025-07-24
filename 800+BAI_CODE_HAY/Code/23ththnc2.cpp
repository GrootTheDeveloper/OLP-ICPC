#include <bits/stdc++.h>
using namespace std;
#define int long long

bool prime[170];
int a[20],n;
int f[20][170];

void sie()
{
	prime[1]=prime[0]=true;
	for (int i=2;i<=sqrt(170);i++)
		if (!prime[i]) for (int j=i*i;j<=170;j+=i) prime[j]=true;
}

int Try(int i, bool lim, int sum)
{
	bool new_lim;
	if (i<1) return (!prime[sum]);
	if (lim==false && f[i][sum]>=0) return f[i][sum];
	int kq=0;
	int mx=(lim? a[i]:9);
	for (int c=0;c<=mx;c++)
	{
		new_lim=(lim && c==mx);
		kq+=Try(i-1,new_lim,sum+c);
	}
	if (lim==false) f[i][sum]=kq;
	return kq;
}

int G(int x)
{
	n=0;
	while (x)
	{
		n++;
		a[n]=x%10;
		x/=10;
	}
	return Try(n,true,0);
}

void solve(int n)
{
	int l=1,r=(int)1e16;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (G(mid)>n) r=mid-1;
		else l=mid+1;
	}
	while (G(l)<n) l++;
	while (G(l-1)>=n) l--;
	cout << l << '\n';
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	sie();
	memset(f,-1,sizeof(f));
	int t; cin >> t;
	while (t--)
	{
		int k; cin >> k;
		solve(k);
	}

}