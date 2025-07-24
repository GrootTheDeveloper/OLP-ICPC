#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <int> d[100005];
int divs[100005],q,mx,mr;
struct dta{
	int l,r,x;
}test[100005]; 
void sie(int N)
{
	for (int i=1;i<=N;i++)
		for (int j=i*2;j<=N;j+=i) divs[j]+=i;
}
void calc(int N)
{
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=1e5;j++)
		if (divs[j]>i) d[i].push_back(j); 
	}
}
void task1()
{
	sie(100000);
	calc(10);
	for (int i=1;i<=q;i++)
	{
		int l=test[i].l,r=test[i].r,x=test[i].x;
		cout << upper_bound(d[x].begin(),d[x].end(),r)-lower_bound(d[x].begin(),d[x].end(),l) << '\n';
	}

}
void task2()
{
	sie(100000);
	for (int i=1;i<=q;i++)
	{
		int l=test[i].l,r=test[i].r,x=test[i].x;
		for (int j=l,res=0;j<=r;j++)
		{
			res+=divs[j]>x;
			if (j==r) cout << res << '\n';
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> q;
	int mx=0;
	for (int i=1;i<=q;i++)
	{
		cin >> test[i].l >> test[i].r >> test[i].x;
		mx=max(mx,test[i].x);
		mr=max(mr,test[i].r);
	}
	if (mx<=10) task1();
	else if (q<=1e3 && mr<=1e3) task2();




}