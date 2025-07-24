#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[7],cnt[4];
int res,s;
void check()
{
	for (int i=1;i<=6;i++) if (a[i]==a[i-1]) return;
	res++;
}

void Try(int i)
{
	if (i==7) return s++,check(),void();
	for (int j=1;j<=3;j++)
	{
		if (cnt[j])
		{
			cnt[j]--;
			a[i]=j;
			Try(i+1);
			cnt[j]++;
		}
	}
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cnt[3]=3;cnt[2]=2;cnt[1]=1;
	Try(1);
	cout << res << ' ' << s;
}