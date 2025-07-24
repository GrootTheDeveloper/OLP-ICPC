#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int n,p; cin >> n >> p;
	int res=0;
	for (int i=p;i<=n;i+=p) res+=(gcd(i,n)==p);
	cout << res;

}