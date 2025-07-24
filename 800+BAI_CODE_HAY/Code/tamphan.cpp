#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,res,a[20];
void Try(int i)
{
	if (i==n+1) return res++,void();
	for (int j=0;j<=2;j++)
	{
		if (j!=1) a[i]=j,Try(i+1);
		else if (j==1 && a[i-1]!=1) a[i]=1,Try(i+1);
	}
}


main()
{
	//ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	if (n<=15) Try(1);
	cout << res;
}