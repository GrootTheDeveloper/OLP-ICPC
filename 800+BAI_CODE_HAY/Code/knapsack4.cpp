#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,mid,m,lima,limb;
bool cnt[40];
struct dta{
    int W=0LL,VAL=0LL;
    vector <int> v;
};
dta a[270000],b[270000],f[270000];
int w[40],v[40],l[270000];
vector <int> tmp,oo;
void check(int lim)
{
    tmp=(oo);
    int Wt=0,Vt=0;
    for (int i=1;i<=n;i++)
    if (cnt[i])
    {
        tmp.push_back(i);
        Wt+=w[i];
        Vt+=v[i];
    }
    if (lim==mid)
    {
        lima++;
        a[lima].W=Wt;
        a[lima].VAL=Vt;
        a[lima].v=(tmp);
    }
    else
    {
        limb++;
        b[limb].W=Wt;
        b[limb].VAL=Vt;
        b[limb].v=(tmp);
    }
}
void Try(int i, int lim)
{
    if (i>lim) return check(lim),void();
    cnt[i]=1;Try(i+1,lim);
    cnt[i]=0;Try(i+1,lim);
}

bool cmp(dta a, dta b)
{
    return a.W<b.W;
}
main()
{
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> w[i] >> v[i];
    mid=n/2; 
    Try(1,mid);
    memset(cnt,0,sizeof(cnt));
    Try(mid+1,n);
    sort(a+1,a+lima+1,cmp);
    for (int i=1;i<=lima;i++)
    {
        if (f[i-1].VAL<a[i].VAL) f[i]=a[i];
        else f[i]=f[i-1];
        l[i]=f[i].W;
    }
    int res=0,x,y;
    for (int i=1;i<=limb;i++)
    if (b[i].W<=m)
    {
        int pos=upper_bound(l+1,l+lima+1,m-b[i].W)-l-1;
        if (f[pos].VAL+b[i].VAL>res) res=f[pos].VAL+b[i].VAL,x=pos,y=i;
    }
    cout << f[x].v.size()+b[y].v.size() << '\n';
    for (int c : f[x].v)
        cout << c << ' ';
    for (int c : b[y].v)
        cout << c << ' ';
    /*cout << lima << '\n';
    for (int i=1;i<=lima;i++) cout << a[i].W << ' ' << a[i].VAL << '\n';
    cout << limb << '\n';
    for (int i=1;i<=limb;i++) cout << b[i].W << ' ' << b[i].VAL << '\n';
    */
}