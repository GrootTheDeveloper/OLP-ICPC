#include <bits/stdc++.h>
using namespace std;
#define int long long
int d[1111][1025],n,k;
const int mode=1e9+7;

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	n=pow(2,n);
	if (n<=1024 && k<=1000)
	{
		for (int i=0;i<n;i++) cin >> d[0][i];
		for (int l=1;l<=k;l++)
		{
			for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			if (i!=j)  d[l][j]=(d[l][j]+d[l-1][i]*(2*(i|j)-i-j))%mode;
		}
		for (int i=0;i<n;i++) cout << d[k][i] << ' ';
	}

}