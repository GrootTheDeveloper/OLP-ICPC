#include <bits/stdc++.h>
using namespace std;
#define int long long 
int dif[1000005];
bool prime[1000006];

void sie()
{
	dif[1]=1;
	for (int i=2;i<=1e6;i++)
	if (!dif[i]) 
	{
		prime[i]=true;
		for (int j=i;j<=1e6;j+=i) dif[j]=i;
	}
}
bool check(int n)
{
	vector <int> ans;
	while (n!=1)
	{
		int k=dif[n],t=0;
		while (n!=1 && n%k==0) t++,n/=k;
		ans.push_back(t*2+1);
	}
	int res=1;
	for (int i : ans) res*=i;
	return prime[res]; 
}

main()
{
	//freopen("bai4.inp","r",stdin);
	//freopen("bai4.out","w",stdout);
	int l,r; cin >> l >> r;
	sie();
	int x=trunc(sqrt(l));
	if (x*x<l) x++;
	int res=0;
	for (int i=x;i*i<=r;i++) res+=check(i);
	cout << res;

}