#include <bits/stdc++.h>
using namespace std;
#define int long long 

int cnt[100];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	int res=0;
	for (int i=1,ai,m;i<=n;i++)
	{
		cin >> ai;
		m=0;
		while (ai%2==0) m++,ai/=2;
		for (int i=0;i<=64;i++) for (int j=i;j<=64;j++)
			if (i+j+m>=k) res+=((i==j)? cnt[i]*(cnt[i]-1)/2: cnt[i]*cnt[j]);
		cnt[m]++;
	}
	cout << res;
	
}