/*
________________________________________________________________________________________________________________
|Name : HuỳnhTấn Đức| ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | Backspace|                            |
|Class: A5K7        |--------------------------------------------------------------|     ++++++                 |
|THPT Đỗ Đăng Tuyển |TAB| Q | W | E | R | T | Y | U | I | O | P | [ | ] | Lovely   |   ++++++++++               |
|Quảng Nam          |--------------------------------------------------------------|  ++++      +               |
|___________________|CapsLK | A | S | D | F | G | H | J | K | L | ; | " | ENTER    |  ++++           *     *    |
|         |(\/)     |--------------------------------------------------------------|  ++++         ***** *****  |
|*=====   |('.')    |   SHIFT   | Z | X | C | V | B | N | M | < | > | ? | SHIFT    |  ++++           *     *    |
|||   "   |(>>T.Đức |--------------------------------------------------------------|  ++++      +               |
|||    ++ |_________|Ctrl|Fn|Win|ALT|         SPACE         |ALT|Ctrl| <- | ^ | -> |   ++++++++++               |
|||       |     (\/)|--------------------------------------------------------------|     ++++++                 |
|*===="   | ***('.')| H | U | Ỳ | N | H | * | T | Ấ  | N | * | Đ | Ứ | C |---------|   Flower in Prison         |
|         | \___/<<)|-------------------------------------------------------------------------------------------|
|         | T.Tuyền |   I LOVE COMPETITIVE PROGRAMMING  | I WILL DISCIPLINE MYSELF TO BECOME MORE SUCCESSFUL    |
|_________|_________|___________________________________________________________________________________________|
 
*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode=1e9+7;
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
	{
		res.d[i][j]+=a.d[i][u]*b.d[u][j];
		if (res.d[i][j]>=mode*mode) res.d[i][j]-=mode*mode;
	}
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) res.d[i][j]%=mode;
	return res;
}

Matrix power(Matrix a,int  b)
{
	int n=a.m;
	Matrix res(n,n);
	for (int i=1;i<=n;i++) res.d[i][i]=1;
	while (b)
	{
		if (b&1) res=mul(res,a);
		a=mul(a,a);
		b/=2;
	}
	return res;
}

int n;

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	Matrix v(1,2);
	v.d[1][1]=0;
	v.d[1][2]=1;
	Matrix g(2,2);
	g.d[1][1]=0;
	g.d[1][2]=1;
	g.d[2][1]=1;
	g.d[2][2]=1;
	cin >> n;
	Matrix res=mul(v,power(g,n));
	cout << res.d[1][1];
}