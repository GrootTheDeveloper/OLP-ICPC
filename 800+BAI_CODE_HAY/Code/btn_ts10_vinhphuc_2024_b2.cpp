#include <bits/stdc++.h>
using namespace std;
#define int long long 

int cnt[1000006];
signed main()
{
	int ans=0;
	int a,b,k;
	cin >> a >> b >> k;
	for (int i=a;i<=b;i++) cnt[i]=(i%k==0),ans+=cnt[i];
	cin >> a >> b >> k;
	for (int i=a;i<=b;i++) ans+=(i%k==0),ans-=cnt[i]*(i%k==0);
	cout << ans;

}