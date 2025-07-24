#include <bits/stdc++.h>
using namespace std;
#define int long long 

bool us[10];
int res=0;
int n,k;

void Try(int i)
{
	if (i==n+1) return res++,void();
	for (int j=1;j<=n;j++)
	{
		if (!us[j] && abs(i-j)<=k)
		{
			us[j]=true;
			Try(i+1);
			us[j]=false;
		}
	}
}
void sub1()
{
	Try(1);
	cout << res;
}

int f[1000005];
const int mode=1e9+7;
void sub2()
{
	f[1]=1;
	f[2]=2;
	for (int i=3;i<=n;i++) f[i]=(f[i-1]+f[i-2])%mode;
	cout << f[n];
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	if (n<=8) sub1();
	else if (n<=1e5 && k==1) sub2();
}