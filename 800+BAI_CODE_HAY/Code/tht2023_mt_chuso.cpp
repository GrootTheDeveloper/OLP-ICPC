#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct Matrix{
	int m,n;
	int d[5][5];
	Matrix(int _m, int _n)
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
		res.d[i][j]=(res.d[i][j]+a.d[i][u]*b.d[u][j])%10;
	return res;
}
Matrix power(Matrix a, int n)
{
	Matrix res(a.m,a.n);
	for (int i=1;i<=res.m;i++) res.d[i][i]=1;
	while (n)
	{
		if (n&1) res=mul(res,a);
		a=mul(a,a);
		n/=2;
	}
	return res;
}
Matrix v(1,2);
Matrix a(2,2);
int calc(int n)
{
	Matrix res=mul(v,power(a,n+1));
	return res.d[1][1];
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	a.d[1][1]=0;
	a.d[1][2]=1;
	a.d[2][1]=1;
	a.d[2][2]=1;
	int t; cin >> t;
	int l,r; 
	while (t--)
	{
		cin >> v.d[1][1] >> v.d[1][2] >> l >> r;
		cout << (calc(r)-calc(l-1)+100)%10;
		cout << '\n';
	}


}