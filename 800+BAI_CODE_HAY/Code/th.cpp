#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define val first
#define id second
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
#define N 1000006
#define inf 1e19
int n,m;
int a[N],ans,s;

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	// freopen("average.inp","r",stdin);
	// freopen("average.out","w",stdout);
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,m) s+=a[i];
	int l=1,r=m+1;
	double avg = s/m;
	while(l<=n and r<=n){
		double tmp = (s+a[r])/(r-l+1);
		if(tmp<avg){
			while(tmp<avg and r-l+1>m){
				s-=a[l]; 
				tmp = (s+a[r])/(r-l+1);
				l++;
			}
			avg=max(avg,tmp);
		}else{
			avg=tmp;
			r++;
		}
	}
	cout<<avg;
}
// 4 2
// 17 0 14 1
// 5 1
// 2 8 -1 4 5