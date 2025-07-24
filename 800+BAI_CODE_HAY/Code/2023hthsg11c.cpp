/*#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,s,k,a[1000006];
unordered_map <int,int> f;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	cin >> k;
	int res=0;
	for (int i=1;i<=n;i++)
	{
		s+=a[i];
		if (s==k) res++;
		if (s>k) res+=f[s-k];
		f[s]++;
	}
	cout << res;
}*/

#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,k,a[100005],f[100005],cnt;

void sol1()
{
	f[1]=a[1];
	f[2]=max(a[2],a[1]);
	for (int i=3;i<=n;i++) f[i]=max(f[i-1],f[i-2]+a[i]);
	cout << f[n];
}
void sol2()
{
	f[1]=a[1];
	f[2]=a[1]+a[2];
	for (int i=3;i<=n;i++) f[i]=max({f[i-1],f[i-2]+a[i],f[i-3]+a[i]+a[i-1]});
	cout << f[n];
}



main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i],cnt+=(a[i]<=0);
	cin >> k;
	if (cnt==n) {cout << 0;exit(0);}
	if (k==1) sol1();
	else sol2();
}











