#include <bits/stdc++.h>
using namespace std;
#define int long long 
int sumdiv[1000006];

void sie(int lim)
{
	for (int i=1;i<=lim;i++)
		for (int j=i*2;j<=lim;j+=i) sumdiv[j]+=i;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int l,d; cin >> l >> d;
	sie(l);
	int res=0;
	for (int i=1;i<l;i++) if (abs(sumdiv[i]-i)<=d) res++;
	cout << res;
	return 0;
}