#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode= 2702200927022011;
int v,h;

void sub1()
{
	int res=0;
	for (int i=1;i<=v;i++) res+=v%i;
	cout << res;

}
int calc(int n)
{
	int res=0;
	for (int i=1;i<=n;i++) res+=n%i;
	return res;
}

void sub2()
{
	int res=0;
	for (int i=v;i<=v+h;i++) res=max(res,calc(i));
	cout << res;
}
main()
{
	freopen("CANDY.INP","r",stdin);
	freopen("CANDY.OUT","w",stdout);
	cin >> v >> h;
	if (h==0) sub1();
	else if  (v+h<=1e6) sub2();
}