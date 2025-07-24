#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode=1e9+7;
int calc(int a)
{
	return (a%mode*((a+1)%mode)/2)%mode;
}
int solve(int n)
{
	int res=0;
	for (int l=1;l<=n;l++)
	{
		int r=n/(n/l);
		int sum=((n/l)%mode)*(calc(r)-calc(l-1)+mode)%mode;
		res=(res+sum)%mode;
		l=r;
	}
	return res;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int l,r; cin >> l >> r;
	cout << (solve(r)-solve(l-1)+mode*mode)%mode;

}