#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n;
int a[20],b[20];
int calc(int x)
{
	for (int i=1;i<=n;i++) b[i]=a[i];
	b[n]=x%10;
	b[n-1]=x/10;
	int k=(a[n]==b[n])+(a[n-1]==b[n-1]);
	for (int i=1;i<=n-2;i++){
		if (i==1){
			if (b[i]!=1 && k) b[i]=1,k--;
		}
		else{
			if (b[i]!=0 && k) b[i]=0,k--;
		}
	}
	if (b[1]==0) return (int)1e18;
	int res=0;
	for (int i=1;i<=n;i++) res=res*10+b[i];
	return res;
	
}
main()
{
	string s; cin >> s;
	n=s.size();
	for (int i=1;i<=n;i++) a[i]=s[i-1]-'0';
	int res=(int)1e18;
	for (int i=0;i<=96;i+=4) res=min(res,calc(i));
	cout << res;

}