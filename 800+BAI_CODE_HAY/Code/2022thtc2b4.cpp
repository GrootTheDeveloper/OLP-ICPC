#include <bits/stdc++.h>
using namespace std;
#define int long long 

unordered_map <int,int> f;
int calc(int l, int r){
	return r*(r+1)/2-l*(l+1)/2;
}

main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("DOVUIVE.INP","r",stdin);
	freopen("DOVUIVE.OUT","w",stdout);
	int n,k; cin >> n >> k;
	priority_queue <int> q;
	int ai;
	for (int i=1;i<=n;i++){
		cin >> ai;
		f[ai]++;
		if (f[ai]==1) q.push(ai);
	}
	q.push(0);
	int val,lim,res=0;
	while (k && q.size()>1){
		val=q.top();
		q.pop();
		lim=q.top();
		if (f[val]*(val-lim)<=k){
			k-=f[val]*(val-lim);
			res+=calc(lim,val)*f[val];
			f[lim]+=f[val];
		}
		else{
			int t=k/f[val];
			res+=calc(val-t,val)*f[val];
			k-=f[val]*t;
			res+=k*(val-t);
			k=0;
		}
	}
	cout << res;
}