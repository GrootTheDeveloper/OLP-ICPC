#include <bits/stdc++.h>
using namespace std;
#define int long long
int m,n,f[111][111];

void solve(string s)
{
    string bthuc="";
    for (int i=0;i<=2;i++) bthuc+=s[i];
    int a=0,b,c=0,d;
    int i=4;
    string s1,s2;
    while (s[i]!=',') s1+=s[i],i++;
    i++;
    while (s[i]!=')') s2+=s[i],i++;
    b=(int)s1[0]-64;d=(int)s2[0]-64;
    for (int i=1;i<s1.size();i++) a=a*10+(s1[i]-'0');
    for (int i=1;i<s2.size();i++) c=c*10+(s2[i]-'0');
    if (bthuc=="MAX") cout << max(f[a][b],f[c][d]);
    else cout << f[a][b]+f[c][d];
    cout << '\n';
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> m >> n;
    for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) cin >> f[i][j];
    int q; cin >> q;
    while (q--)
    {
        string s; cin >> s;
        solve(s);
    }
}
