#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n,mid,a[10004],sum;
vector <int> v1,v2;
bool cou[50];
void check(int lim)
{
	int res=0;
	for (int i=1;i<=n;i++) res+=cou[i]*a[i];
	if (lim==mid) v1.push_back(res);
	else v2.push_back(res);
}
void Try(int i, int lim)
{
	if (i>lim) return check(lim),void();
	cou[i]=0;
	Try(i+1,lim);
	cou[i]=1;
	Try(i+1,lim);
}


void sub1()
{
	mid=n/2;
	Try(1,mid);
	memset(cou,0,sizeof(cou));
	Try(mid+1,n);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int s=sum/2;
	int res=(int)1e18;
	for (int c : v1)
	{
		auto it=upper_bound(v2.begin(),v2.end(),s-c);
		if (it!=v2.begin()) it--;
		else continue;
		res=min(res,abs(sum-2*(c+*it)));
	}
	cout << res;
}

bitset <1000000> d,temp;

void sub2()
{
	temp.set(0);
	for (int i=1;i<=n;i++)
	{
		d=((temp<<a[i])|temp);
		temp=d;
	}
	for (int i=sum/2;i>=0;i--)
		if (d[i]==1) return cout << sum-2*i,void();
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("CANDY.INP","r",stdin);
	freopen("CANDY.OUT","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i],sum+=a[i];
	if (n<=40) sub1();
	else sub2();
}