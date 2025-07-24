#include <bits/stdc++.h>
using namespace std;
#define int long long 

int cnt[5000006];
int divs[5000006];
void sie_div(int N)
{
	int lim=trunc(sqrt(N));
	for (int i=2;i<=lim;i++)
		if (!divs[i]) for (int j=i*i;j<=N;j+=i) divs[j]=i;
	divs[2]=2;
	for (int i=3;i<=N;i+=2) if (!divs[i]) divs[i]=i;
}
int coun[5000006];
int a[100];
int get_div(int n)
{
	int k=0;
	while (n!=1)
	{
		coun[divs[n]]++;
		if (coun[divs[n]]==1) a[++k]=divs[n];
		n/=divs[n];
	}
	int oo=1;
	for (int i=1;i<=k;i++) 
	{
		if (coun[a[i]]&1) oo*=a[i];
		coun[a[i]]=0;
	}
	return oo;
}
int comb2(int n) { return n*(n-1)/2;}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	sie_div(n);
	int res=0;
	for (int i=1;i<=n;i++)
	{
		int k=get_div(i);
		res+=comb2(cnt[k]);
		cnt[k]++;
	}
	cout << res;
}