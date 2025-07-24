#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode=1e9+7;
int n,k;

int cnt[15];
void sub(int n, int k)
{
	memset(cnt,0,sizeof(cnt));
	while (n) cnt[n%10]++,n/=10;
	for (int i=1;i<=k;i++)
	{

		for (int j=10;j>=1;j--)
			cnt[j]=cnt[j-1];
		cnt[0]=cnt[10];
		cnt[1]=(cnt[1]+cnt[10])%mode;
	}
	int res=0;
	for (int i=0;i<=9;i++) res=(res+cnt[i])%mode;
	cout << res << '\n';
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("CONG.INP","r",stdin);
	freopen("CONG.OUT","w",stdout);
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		sub(n,k);
	}
}