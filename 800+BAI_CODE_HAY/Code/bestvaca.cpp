#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int,int>
#define fi first
#define se second
const int mode=1e9+7,N=1e6+7;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int n,m,x;
int a[1000006],f[1000006];
int calc(int n){ return n*(n+1)/2;}
int fast(int l, int r) {return calc(r)-calc(l-1);}
void ReadText()
{
	cin >> n >> x;
	for (int i=1;i<=n;i++) cin >> a[i],f[i]=f[i-1]+calc(a[i]);
	//for (int i=1;i<=n;i++) cout << f[i] << ' ';
}

void solve()
{
	int l=0,res=0,s=0;
	for (int r=1;r<=n;r++)
	{
		s+=a[r];
		while (s>x && l<r) s-=a[l++];
		if (l<r)
		{
			int ans=(f[r]-f[l-1])%mode;
			int k=x-s;
			if (k>0) ans+=fast(a[l-1]-k+1,a[l-1]);
			res=max(res,ans%mode);
		}
		if (l==r) res=max(res,fast(a[r]-x+1,a[r]));
	}
	cout << res;
}

signed main()
{
	fastIO();
	ReadText();
	solve();
}