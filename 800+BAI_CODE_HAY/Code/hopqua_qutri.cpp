#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200006],cnt[1000006];
int calc(int n)
{
	n-=2;
	return n*(n+1)/2;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,d; cin >> n >> d;
	for (int i=1;i<=n;i++) cin >> a[i],cnt[a[i]]++;
	int k=0;
	for (int i=1;i<=1e6;i++)
	{
		while (cnt[i]) k++,a[k]=i,cnt[i]--;
	}
	int l=1,res=0;
	for (int i=3;i<=n;i++)
	{
		while (a[i]-a[l]>d) l++;
		if (i-l+1>=3) res+=calc(i-l+1);
	}
	cout << res;
}