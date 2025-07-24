#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long 
const int mode=1e9+7;

struct Matrix{
	int m,n;
	int d[5][5];
	Matrix(int _m=0,int _n=0)
	{
		m=_m;n=_n;
		memset(d,0,sizeof(d));
	}
};

Matrix mul(Matrix a, Matrix b)
{
	int m=a.m,n=b.n,k=a.n;
	Matrix res(m,n);
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++)
	for (int u=1;u<=k;u++)
	{
		res.d[i][j]+=a.d[i][u]*b.d[u][j];
		while (res.d[i][j]>=mode*mode) res.d[i][j]-=mode*mode;
	}
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) res.d[i][j]%=mode;
	return res;
}
Matrix power(Matrix a, int b)
{
	Matrix res(a.m,a.n);
	for (int i=1;i<=res.n;i++) res.d[i][i]=1;
	while (b)
	{
		if (b&1) res=mul(res,a);
		a=mul(a,a);
		b/=2;
	}
	return res;
}

void solve(int n)
{
	Matrix v(1,2);
	v.d[1][1]=1;
	v.d[1][2]=1;
	Matrix a(2,2);
	a.d[1][1]=0;
	a.d[1][2]=1;
	a.d[2][1]=1;
	a.d[2][2]=1;
	Matrix res=mul(v,power(a,n-1));
	cout << res.d[1][1];
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	solve(n);
}