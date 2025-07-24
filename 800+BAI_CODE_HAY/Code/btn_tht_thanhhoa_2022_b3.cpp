#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
unordered_map <int,int> f;
int a[3333];

int check(int n)
{
    int lim=sqrt(n);
    if (lim*lim!=n) return 0;
    if (f.find(lim)!=f.end()) return f[lim];
    return 0;
}
signed main()
{
    int x,y,z,n; cin >> x >> y >> z >> n;
    int k=0;
    for (int i=x;i<x+n;i++) a[++k]=i,f[i]++;
    for (int i=y;i<y+n;i++) a[++k]=i,f[i]++;
    for (int i=z;i<z+n;i++) a[++k]=i,f[i]++;
    int res=0;
    for (int i=1;i<k;i++)
    for (int j=i+1;j<=k;j++)
        res+=check(a[i]*a[i]+a[j]*a[j]);
    cout << res;

}
