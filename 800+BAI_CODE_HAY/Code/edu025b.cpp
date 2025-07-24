#include <bits/stdc++.h>
using namespace std;
#define int long long 

int sl(int n)
{
	int res=0;
	while (n!=0) res++,n/=10;
	return res;
}
int f[10];
main()
{
	freopen("SONHA.INP","r",stdin);
	freopen("SONHA.OUT","w",stdout);
	int n; cin >> n;
	f[1]=9;
	for (int i=2;i<=9;i++) f[i]=f[i-1]*10;
	int k=sl(n);
	int res=(n-pow(10,k-1)+1)*k;
	for (int i=1;i<k;i++) res+=f[i]*i;
	cout << res*80000;
}