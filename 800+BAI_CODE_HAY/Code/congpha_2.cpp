#include <bits/stdc++.h>
using namespace std;
#define int long long 
int cnt[1000006];
void sie()
{
	for (int i=2;i<=1e6;++i) for (int j=i;j<=1e6;j+=i)
		cnt[j]++;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,res=0,ai; cin >> n;
	sie();
	for (int i=1;i<=n;i++) cin >> ai,res+=ai*(cnt[ai]+1);
	cout << res;

	
}