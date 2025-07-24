#include <bits/stdc++.h>
using namespace std;
#define int long long
int power(int a, int b, int mode)
{
	int res=1;
	while(b)
	{
		if (b&1) res=(res*a)%mode;
		a=(a*a)%mode;
		b/=2;
	}
	return res;
}
bool test(int a, int n, int k, int m)
{
	int mod=power(a,m,n);
	if (mod==1 || mod==n-1) return true;
	for (int l=1;l<=k;l++)
	{
		mod=(mod*mod)%n;
		if (mod==n-1) 
			return true;
	}
	return false;
}

bool miller_check(int n)
{
	if (n==2 || n==3 || n==5 || n==7) return true;
	if (n<11) return false;
	int k=0,m=n-1;
	while (m%2==0)
	{
		k++;
		m/=2;
	}
	vector <int> settest={2,3,5,7,11,13,17,19,23,29,31,37};
	for (int a: settest)
		if (!test(a,n,k,m)) return false;
	return true;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("t.inp","r",stdin);
	//freopen("t.out","w",stdout);
	int n; cin >> n;
	while (n--)
	{
		int x; cin >> x;
		if (miller_check(x)) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	cout << clock()/(double)1000;
}