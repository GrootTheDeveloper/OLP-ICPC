#include <bits/stdc++.h>
using namespace std;
#define int long long 
int sum(int n) 
{
	int res=0;
	while (n) res+=n%10,n/=10;
	return res;
}
main()
{
	int n; cin >> n;
	while (n>9) n=sum(n);
	cout << n;
}