#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool prime[101];
int  a[10],n;
int f[10][100];
void sie()
{
	prime[1]=prime[0]=true;
	for (int i=2;i<=10;i++) 
		if (!prime[i]) for(int j=i*i;j<=100;j+=i) prime[j]=true;
}

int Try(int i, bool lim, int sum)
{
	bool new_lim;
	if (i<1)
	{
		if (!prime[sum]) return 1;
		else return 0;
	}
	if (lim==false && f[i][sum]>=0) return f[i][sum];
	int kq=0;
	int maxc=(lim? a[i]:9);
	for (int c=0;c<=maxc;c++)
	{
		new_lim=(lim && c==maxc);
		kq+=Try(i-1,new_lim,sum+c);
	}
	if (lim==false) f[i][sum] = kq;
	return kq;

}

int G(int val)
{
	n=0;
	a[0]=0;
	while (val)
	{
		n++;
		a[n]=val%10;
		val/=10;
	}
	return Try(n,true,0);

}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int a,b; cin >> a >> b;
	sie();
	memset(f,-1,sizeof(f));
	cout << G(b)-G(a-1);
}