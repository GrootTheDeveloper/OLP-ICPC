#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int,int>
#define fi first
#define se second
const int mode=1e9+7,N=1e6+7;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

struct Matrix{
	int m,n;
	int d[555][555];
	Matrix(int _m=0, int _n=0)
	{
		m=_m;n=_n;
		memset(d,0,sizeof(d));
	}
};

Matrix mul(Matrix a, Matrix b)
{
	int m=a.m,n=b.n,k=a.n;
	Matrix res(m,n);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			for (int u=1;u<=k;u++)
			{
				res.d[i][j]+=a.d[i][u]*b.d[u][j];
				if (res.d[i][j]>=1LL*mode*mode) res.d[i][j]-=mode*mode;
			}	
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) res.d[i][j]%=mode;
	return res;
}
Matrix power(Matrix a, int n)
{
	int x=a.m,y=a.n;
	Matrix res(x,y);
	for (int i=1;i<=x;i++) res.d[i][i]=1;
	while (n)
	{
		if (n&1) res=mul(res,a);
		a=mul(a,a);
		n/=2;
	}
	return res;
}

int n,m;
int a[1000006];
bool check(Matrix a, Matrix b)
{
	for (int i=1;i<=a.m;i++) for (int j=1;j<=a.n;j++) 
	if (a.d[i][j]!=b.d[i][j]) return false;
	return true;
}
void show(Matrix a)
{
	for (int i=1;i<=a.m;i++) 
	{
		for(int j=1;j<=a.n;j++) cout << a.d[i][j] << ' ';
		cout << '\n';
	}
}
void ReadText()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		Matrix a(n,n);
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin >> a.d[i][j];
		Matrix b(n,n);
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin >> b.d[i][j];
		cout << (check(power(a,3),b)? "YES":"NO") << '\n'; 
		
	}
}
void solve()
{
	
}

signed main()
{
	fastIO();
	ReadText();
	solve();
}