/*#include <bits/stdc++.h>
using namespace std;
#define int long long 
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int h)
{
	return l+rd()%(h-l+1);
}

int mul(int a, int b, int mode)
{
	int res=0;
	while (b)
	{
		if (b&1) res=(res+a)%mode;
		a=(a+a)%mode;
		b/=2;
	}
	return res;
}
int Pow(int a, int b, int mode)
{
	int res=1;
	while (b)
	{
		if (b&1) res=mul(res,a,mode);
		a=mul(a,a,mode);
		b/=2;
	}
	return res;
}
bool nt(int n)
{
	if (n<=3) return n>1;
	for (int i=1;i<=100;i++)
	{
		int x=Rand(2,n-1);
		if (Pow(x,n-1,n)!=1) return false;
	}
	return true;
}
bool snt(int n)
{
	while (nt(n)) n/=10;
	return (n==0);
}
main()
{
	int n; cin >> n;
	cout << ((snt(n))? "PHAI":"KHONG");
}
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long 

bool nt(int n) 
{
	if (n<=3) return n>1;
	if (n%2==0 || n%3==0) return false;
	int x=trunc(sqrt(n));
	for (int i=5;i<=x;i+=6)
		if(n%i==0 || n%(i+1)==0) return false;
	return 1;
}
bool snt(int n)
{
	while (nt(n)) n/=10; 
	return n==0;
}
main()
{
	
	int n; cin >> n;
	cout << ((snt(n))? "PHAI":"KHONG");
}
