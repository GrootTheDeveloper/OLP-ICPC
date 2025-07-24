#include <bits/stdc++.h>
using namespace std;
#define int long long
bool prime[5000006];
void sie(int n)
{
	int lim=(int)sqrt(n);
	for (int i=2;i<=lim;i++)
		if (!prime[i]) for (int j=i*i;j<=n;j+=i) prime[j]=true;
}
int s(int n)
{
	int res=0;
	while (n) res+=n%10, n/=10;
	return res;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("DOCAONT.INP","r",stdin);
	freopen("DOCAONT.OUT","w",stdout);
	int n,h; cin >> n >> h;
	sie(n);
	int cnt=0;
	for (int i=2;i<=n;i++) if (!prime[i] && s(i)==h) cout << i << '\n',cnt++;
	cout << cnt;
}