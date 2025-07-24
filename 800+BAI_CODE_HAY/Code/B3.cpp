#include <bits/stdc++.h>
using namespace std;
#define int long long 
pair<int,int> a[100005];
int n,m;
void sol1()
{
	int res=0;
	while (m--)
	{
		int temp=0,id=0;
		for (int i=1;i<=n;i++) if (a[i].first+a[i].second>temp) temp=a[i].first+a[i].second,id=i;
		res+=temp; 
		a[id].first=0; 
	}
	cout << res;
}
bool cmp( pair<int,int> a, pair<int,int> b)
{
	return a.first+a.second>b.first+b.second;
}
void sol2()
{
	int res=0;
	sort(a+1,a+n+1,cmp);
	int rot=0;
	for (int i=1;i<=n;i++)
	{
		if (m==0) break;
		if (rot<a[i].first+a[i].second) 
		{
			res+=a[i].first+a[i].second;
			a[i].first=0;
			rot=max(rot,a[i].second);
			m--;
		} 
		else break;
	}
	res+=m*rot;
	cout << res;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i].first >> a[i].second;
	if (m<=100) sol1();
	else sol2();
}