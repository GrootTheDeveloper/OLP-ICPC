 #include <bits/stdc++.h>
using namespace std;
#define int long long
int f[10000];
int ucln(int a, int b)
{
	if (b==0) return a;
	return ucln(b,a%b);
}

main()
{
	 int n,m; cin >> n >> m;
	f[1]=1;
	f[2]=1;
	for (int i=3;i<=n;i++) f[i]=f[i-1]+f[i-2];
	cout << f[n] << endl;
	cout << ucln(n,m);
}
