#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;

int power(int a, int b)
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
int comb(int k, int n)
{
	int a=1,b=1;
	for (int i=k+1;i<=n;i++) a=(a*i)%mode;
	for (int i=1;i<=n-k;i++) b=(b*i)%mode;
	return a*power(b,mode-2)%mode;
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	cout << comb(k-1,n-1);

}