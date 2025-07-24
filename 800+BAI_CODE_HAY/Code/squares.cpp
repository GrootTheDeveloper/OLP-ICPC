#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[4];
main()
{
	int n;cin >> n;
	a[1]=n;a[2]=n+1;a[3]=2*n+1;
	for (int i=1;i<=3;i++) if (a[i]%2==0) {a[i]/=2;break;}
	for (int i=1;i<=3;i++) if (a[i]%3==0) {a[i]/=3;break;}
	cout << ((a[1]%2013)*(a[2]%2013)*(a[3]%2013))%2013;

}