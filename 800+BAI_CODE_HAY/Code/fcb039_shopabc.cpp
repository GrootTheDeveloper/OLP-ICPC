#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
int pre[MAXN],f[MAXN],res=0,n;
string s;
int bin(int l, int r, int val)
{
    while (l<r)
    {
        int mid=(l+r)/2;
        if (val-f[mid]>0) r=mid;
        else l=mid+1;
    }
    return l;
}

void sol(char x)
{
    for (int i=1;i<=n;i++){
        pre[i]=pre[i-1]+(s[i]==x? 1:-1);
        f[i]=min(f[i-1],pre[i]);
    }
    for (int i=1;i<=n;i++)
    {
        int l=bin(0,i,pre[i]);
        if (pre[i]-pre[l]>0) res=max(res,i-l);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s; s=' '+s;
    sol('a');
    sol('b');
    sol('c');
    cout << res;

}
