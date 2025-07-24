//https://codeforces.com/gym/512327/problem/A

#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool prime[32005];
void sie()
{
	int lim=trunc(sqrt(32000));
	for (int i=2;i<=lim;i++)
		if (!prime[i]) for (int j=i*i;j<=32000;j+=i)
			prime[j]=true;
}
main()
{
	int n; cin >> n;
	sie();
	int lim=(int)sqrt(sqrt(n));
	int res=0;
	for (int i=2;i<=lim;i++) if (!prime[i]) res++;
	cout << res;
}