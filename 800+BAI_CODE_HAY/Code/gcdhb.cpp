#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ai,bi,a[100005],b[100005],divs[100005];
const int mode=1e9+7;

void o_o()
{
	for (int i=2;i<=1e5;i++)
	if (!divs[i]) for (int j=i;j<=1e5;j+=i) divs[j]=i;
}
void put(int n, char c)
{
	while (n!=1)
	{
		if (c=='a') a[divs[n]]++;
		else        b[divs[n]]++;
		n/=divs[n];
	}
}
int power(int a, int b)
{
	int res=1;
	while (b)
	{
		if (b&1) res=(res*a)%mode;
		a=(a*a)%mode;
		b/=2;
	}
	return res;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	o_o();
	cin >> n;
	for (int i=1;i<=n;i++) 
	{
		cin >> ai;
		put(ai,'a');
	}
	cin >> m;
	for (int i=1;i<=m;i++) 
	{
		cin >> bi;
		put(bi,'b');
	}
	int res=1;
	for (int i=2;i<=1e5;i++)
		if (a[i] && b[i]) res=(res*power(i,min(a[i],b[i])))%mode;
	cout << res;
}