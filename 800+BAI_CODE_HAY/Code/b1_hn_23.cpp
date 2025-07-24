#include <bits/stdc++.h>
using namespace std;
#define int long long 
int prime[1000006],l,r;

void sie(int N)
{
	int lim=trunc(sqrt(N));
	prime[1]=true;
	for (int i=2;i<=lim;i++)
	if (!prime[i]) for (int j=i*i;j<=N;j+=i) prime[j]=true;
	
}

main()
{
	cin >> l >> r;
	sie(trunc(sqrt(r)));
	int x=trunc(sqrt(l)),y=trunc(sqrt(r));
	if (x*x<l) x++;
	int res=0;
	for (int i=x;i<=y;i++) res+=(!prime[i]);
	cout << res;
}