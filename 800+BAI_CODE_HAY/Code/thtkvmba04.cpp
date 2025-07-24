#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[10],cnt,cnt1,cnt2;
int res=0;
void add(int i) 
{
	f[i]++;
	cnt+=(f[i]&1);
	cnt-=(f[i]%2==0);
	cnt1+=(i==0);
	cnt2+=(i!=0);
}
void put()
{
	for (int i=1;i<=f[0]/2;i++) res=res*10;
}
void push(int l)
{
	for (int i=1;i<=f[l]/2;i++) 
	{
		res=res*10+l;
		if (res<10) put();
	} 
}

main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n; cin >> n;
	while (n!=0) add(n%10), n/=10;
	if (cnt>1 || (cnt1>0 && cnt2==1)) {cout << 0; exit(0);}
	int k=-1;
	for (int i=0;i<=9;i++)
		if (f[i]&1) k=i, f[i]--;
	for (int i=1;i<=9;i++)
	{
		if (f[i]) push(i);
	}
	if (res!=0) cout << res;
	if (k!=-1) cout << k;
	while (res) cout << res%10, res/=10;


}
