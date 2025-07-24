#include <bits/stdc++.h>
using namespace std;
const int N=1100000;
int t[N*4],a[N],li[N*4],ri[N*4],cnt[3];
void build(int id , int l, int r)
{
    li[id]=l;
    ri[id]=r;
    if (l==r) return t[id]=a[l],void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=t[id*2]+t[id*2+1];
}
void hai(int id)
{
    if (li[id]!=ri[id])
    {
        if (t[id*2]>=t[id*2+1])
            hai(id*2);
        else
            hai(id*2+1);
        t[id]=t[id*2]+t[id*2+1];
    }
    else
    {
        cout << li[id] << ' ';
        t[id]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n; n=pow(2,n);
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (a[i]>=1 && a[i]<=2) cnt[a[i]]++;
    }
    if (cnt[2]>1 || cnt[2]+cnt[1]!=n) return cout << 0,0;
    cout << n << endl;
    build(1,1,n);
    for (int i=1;i<=n;i++)
        hai(1);
    return 0;
}
