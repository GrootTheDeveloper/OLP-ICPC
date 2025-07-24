#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],cnt[5555];
int count1,count2;
bool us[5555];
void add(int val) {cnt[val]++;count1+=(cnt[val]==1);}
void pull(int val)
{
	if (cnt[val]==0) count2=0;
	if (cnt[val])
	{
		count2+=(!us[val]);
		us[val]=true;
	}
}
void sub1()
{
	int res=0;
	for (int i=1;i<n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		count1=0;
		for (int j=i;j<n;j++)
		{
			add(a[j]);
			memset(us,0,sizeof(us));
			count2=0;
			for (int k=j+1;k<=n;k++)
			{
				pull(a[k]);
				if (count2==0) break;
				res+=(count2==count1);
			}

		}

	}
	cout << res;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	if (n<=5000) sub1();

}