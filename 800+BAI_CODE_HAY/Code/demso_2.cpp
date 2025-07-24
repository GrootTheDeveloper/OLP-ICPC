#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
const int mode=1e9+7;
bool f[165][5135];
ii dp[20][185][5135];
int coso[20],n,a[20],wi[10];

int gcd(int a, int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

void sie()
{
	for (int i=0;i<=19;i++) for (int j=0;j<=180;j++) for (int k=0;k<=5132;k++) dp[i][j][k]=ii{-1,0};
	for (int i=1;i<=162;i++) for (int j=1;j<=5132;j++) f[i][j]=(gcd(i,j)==1);
	coso[1]=1;
	for (int i=2;i<=19;i++) coso[i]=(coso[i-1]*10)%mode;
	for (int i=1;i<=9;i++) wi[i]=wi[i-1]+i*i;

}


ii calc(int i, bool lim, int sum, int wibu)
{
	if (i<1) return {0,f[sum][wibu]};
	if (lim==false && dp[i][sum][wibu]!=ii{-1,0}) return dp[i][sum][wibu];
	ii res={0,0};
	int mx=(lim? a[i]:9);
	for (int c=0;c<=mx;c++)
	{
		ii next=calc(i-1,lim && c==mx, sum+c, wibu+wi[c]);
		res.first=((res.first+next.first)%mode + (c*coso[i]*next.second)%mode)%mode;
		res.second=(res.second+next.second)%mode;
	}
	if (!lim) dp[i][sum][wibu]=res;
	return res;
}

int G(int x)
{
	n=0;
	while (x)
	{
		n++;
		a[n]=x%10;
		x/=10;
	}
	return calc(n,true,0,0).first;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int t; cin >> t;
	sie();
	int x,y;
	while (t--)
	{
		cin >> x >> y;
		cout << (G(y)-G(x-1)+mode*mode)%mode << '\n';
	}
}