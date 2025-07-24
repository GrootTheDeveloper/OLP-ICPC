#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

struct dta
{
    int num1,num2,sum;
};
dta a[100005];

void solve()
{
    int lim=trunc(sqrt(n));
    for (int i=1;i<=lim;i++)
        for (int j=i;j<=lim;j++)
        if (i*i+j*j<n)
        {
            int k=i*i+j*j;
            if (a[k].sum<i+j) a[k].sum=i+j,a[k].num1=i,a[k].num2=j;
        }
    int x=0,s=0;
    for (int i=1;i<n;i++)
        if (a[i].sum && a[n-i].sum)
        {
            int k=a[i].sum+a[n-i].sum;
            if (k>s) s=k,x=i;
        }
    if (x==0) return cout << -1,void();
    vector <int> vi;
    vi.push_back(a[x].num1);
    vi.push_back(a[x].num2);
    vi.push_back(a[n-x].num1);
    vi.push_back(a[n-x].num2);
    sort(vi.begin(),vi.end());
    for (int c : vi) cout << c << ' ';

}



main()
{
    freopen("CHINHPHUONG.INP","r",stdin);
    freopen("CHINHPHUONG.OUT","w",stdout);
    cin >> n;
    solve();
}
