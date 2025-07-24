#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int>  d1[40],d2[40];
int a[40],n,m,s,mid;
bool cnt[40];


void check(int lim)
{
	int k=0,sum=0;
	for (int i=1;i<=n;i++) k+=cnt[i],sum+=a[i]*cnt[i];
	if (lim==mid) d1[k].push_back(sum);
	else d2[k].push_back(sum);
}


void Try(int i, int lim)
{
	if (i>lim) return check(lim),void();
	cnt[i]=1;Try(i+1,lim);
	cnt[i]=0;Try(i+1,lim);
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m >> s;
	for (int i=1;i<=n;i++) cin >> a[i];
	mid=n/2;
	Try(1,mid);
	memset(cnt,0,sizeof(cnt));
	Try(mid+1,n);
	int res=0;
	for (int i=1;i<=m;i++) sort(d2[i].begin(),d2[i].end());

	for (int size=0;size<=m;size++)
	{
		for (int c : d1[size])
		{
			res+=upper_bound(d2[m-size].begin(),d2[m-size].end(),s-c)
				 -lower_bound(d2[m-size].begin(),d2[m-size].end(),s-c);
		}
	}
	cout << res;



}