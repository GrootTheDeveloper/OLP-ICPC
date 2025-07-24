#include <bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> a[1] >> a[2] >> a[3];
	sort(a+1,a+4);
	int res=0;
	res+=a[3]-a[2];
	a[2]=a[3];
	a[1]+=res;
	if ((a[3]-a[1])&1) res+=(a[3]-a[1])/2+2;
	else res+=(a[3]-a[1])/2;
	cout << res;

}