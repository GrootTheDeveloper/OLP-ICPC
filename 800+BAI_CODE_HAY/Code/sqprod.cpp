#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode=1234567891;
int cnt[100005],divs[100005];
void sie()
{
	for (int i=2;i<=1e5;i++)
	if (divs[i]==0)  for (int j=i;j<=1e5;j+=i) divs[j]=i;
}
void pt(int n)
{
	while (n!=1)
	{
		cnt[divs[n]]++;
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
	sie();
	int n;cin >> n;
	for (int i=2;i<=n;i++) pt(i);
	int res=1;
	for (int i=2;i<=n;i++)
	{
		if (cnt[i]&1) cnt[i]--;
		res=(res*power(i,cnt[i]))%mode;
	}
	cout << res;


}