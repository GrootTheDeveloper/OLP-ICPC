#include <bits/stdc++.h>
using namespace std;
#define int long long


int power(int a, int b, int mode)
{
	int res=1;
	while (b)
	{
		if (b&1) res=(res*a)%mode;
		a=(a*a)%mode;
		b/=2;
	}
	return res;
}
bool check(int a, int n, int m, int k)
{
	int mode=power(a,m,n);
	if (mode==1 || mode==n-1) return true;
	for (int l=1;l<=k;l++)
	{
		mode=(mode*mode)%n;
		if (mode==n-1) return true;
	}
	return false;
}

bool nto(int n)
{
	if (n==2 || n==3 || n==5 || n==7) return true;
	if (n<11) return false;
	int m=n-1,k=0;
	while (m%2==0)
	{
		k++;
		m/=2;
	}
	const static int repeatTime = 3;
    for (int i = 0; i < repeatTime; ++i)
    {
        long long a = rand() % (n - 3) + 2;
        if (!check(a, n, m, k))
            return false;
    }
    return true;
}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("SODOCLA.INP","r",stdin);
	//freopen("SODOCLA.OUT","w",stdout);
	int n,ai;
	cin >> n;
	while (n--)
	{
		cin >> ai;
		if (nto(ai)) cout << "NO";
		else cout << "YES";
		cout << '\n';
	}
//999999998719
}