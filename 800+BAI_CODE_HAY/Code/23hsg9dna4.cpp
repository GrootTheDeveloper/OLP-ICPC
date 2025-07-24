#include <bits/stdc++.h>
using namespace std;
#define int long long 

int f[20],a[20],res,si;
bool u[10];
void check()
{
	if (a[1]==0) return;
	int s=0;
	for (int i=1;i<=si;i++) s=s*10+a[i]; 
	res+=s;
}
void Try(int i)
{
	if (i>si) return check(),void();
	for (int j=1;j<=si;j++)
	if (u[f[j]]==false)
	{
		u[f[j]]=true;
		a[i]=f[j];
		Try(i+1);
		u[f[j]]=false;
	}

}
main()
{
	freopen("THV.INP","r",stdin);
	freopen("THV.OUT","w",stdout);
	int n; cin >> n;
	string s=to_string(n);
	si=s.size();
	for (int i=1;i<=si;i++) f[i]=n%10,n/=10;
	Try(1);
	cout << res;
}