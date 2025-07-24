#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool prime[10000007];
void sie(int N)
{
	int lim=trunc(sqrt(N));
	prime[1]=true;
	for (int i=2;i<=lim;i++) 
		if (!prime[i]) for (int j=i*i;j<=N;j+=i) prime[j]=true;

}

signed main()
{
	int n,k; cin >> n >> k;
	sie(n);
	int l=1,res=0,count=0;
	for (int r=1;r<=n;r++)
	{
		count+=(!prime[r]);
		while (count>=k) count-=(!prime[l++]);
		res+=l-1;
	}
	cout << res;
}