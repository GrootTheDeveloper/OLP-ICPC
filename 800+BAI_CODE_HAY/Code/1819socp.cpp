#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode=1e9+7;
int f[40005],divs[400005];

void sie(int n)
{
	int lim=(int)sqrt(n);
	for (int i=2;i<=lim;i++)
		if (!divs[i]) for (int j=i*i;j<=n;j+=i) divs[j]=i;
	for (int i=2;i<=n;i++) if (divs[i]==0) divs[i]=i;
}
void process(int n)
{
	while (n!=1)
	{
		f[divs[n]]++;
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
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	sie(n);
	int res=1;
	for (int i=2;i<=n;i++) process(i);
	for (int i=2;i<=n;i++)
		res=(res*power(i,f[i]-(f[i]&1)))%mode;
	cout << res;

}