#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e18;
struct dt{
    int pos,sl,cs;
};
bool cmp(dt a, dt b)
{
    return a.pos < b.pos;
}
vector<dt> vi;
int l[200005],r[200005],n;

void build()
{
    int sum=vi[0].sl;
    for (int i=0;i<n;i++)
    {
        if (i!=0) l[i]=(l[i-1]%mode+sum*(vi[i].pos-vi[i-1].pos%mode))%mode,sum+=vi[i].sl;
    }
    sum=vi[n-1].sl;
    for (int i=n-1;i>=0;i--)
    {
        if (i!=n-1) r[i]=(r[i+1]%mode+sum*(vi[i+1].pos-vi[i].pos)%mode)%mode,sum+=vi[i].sl;
    }
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        dt x; cin >> x.pos >> x.sl;
        x.cs=i;
        vi.push_back(x);
    }
    sort(vi.begin(),vi.end(),cmp);
    build();
    int res=0,MIN=1e18;
    for (int i=0;i<n;i++)
    {
        if (i==0)
        {
            if (MIN>=r[i]) MIN=r[i],res=i;
        }
        else if (i==n-1)
        {
            if (MIN>=l[i]) MIN=l[i],res=i;
        }
        else if (l[i]+r[i]<=MIN)
        {
            MIN=l[i]+r[i];
            res=i;
        }
    }
    //for (int i=0;i<n;i++) cout << l[i] << ' ' << r[i] << endl;
    cout << vi[res].cs;
}
