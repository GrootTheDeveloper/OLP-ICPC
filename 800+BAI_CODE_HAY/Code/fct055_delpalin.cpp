#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
bool f[333][333];
void result()
{
    int res=0,x=1,y=1,j;
    memset(f,0,sizeof(f));
    int n=s.size()-1;
    for (int i=1;i<=n+1;i++) f[i][i]=1;
    for (int l=2;l<=n;l++)
    {
        for (int i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            if (l==2 && s[i]==s[j]) f[i][j]=1;
            else if (f[i+1][j-1]==1 && s[i]==s[j])
                {
                    f[i][j]=1;
                    if (res<j-i+1) res=j-i+1,x=i,y=j;
                }
        }
    }
    string st="";
    for (int i=0;i<x;i++) st+=s[i];
    for (int i=y+1;i<=n;i++) st+=s[i];
    s=st;
}


int solve()
{
    int res=0;
    while (s.size()!=1) result(),res++;
    return res;
}



main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t; cin >> t;
    while (t--)
    {
        cin >> s;
        s='0'+s;
        cout << solve() << '\n';
    }
}
