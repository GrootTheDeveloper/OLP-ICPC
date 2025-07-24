#include <bits/stdc++.h>
using namespace std;
bool f[10001][10001];
struct dta{int fi,se;};
vector <dta> vi;
string s;
bool cmp(dta a, dta b)
{
     if (a.se-a.fi==b.se-b.fi)
     {
         return s[a.fi]-'0'>s[b.fi]-'0';
     }
     return a.se-a.fi>b.se-b.fi;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> s;
    int n=s.size();
    s=' '+s; f[n][n]=true;
    for (int i=1;i<n;i++)
    {
        f[i][i]=true;
        if (s[i]==s[i+1]) f[i][i+1]=true;
    }
    for (int k=3;k<=n;k++)
    {
        for (int i=1;i+k-1<=n;i++)
        {
            if (s[i]==s[i+k-1]) f[i][i+k-1]=f[i+1][i+k-2];
            if (f[i][i+k-1] && s[i]!='0') {dta x; x.fi=i; x.se=i+k-1;vi.push_back(x);}
        }
    }
    sort(vi.begin(),vi.end(),cmp);
    dta x=*vi.begin();
    cout << x.se-x.fi+1 << endl;
    for (int i=x.fi;i<=x.se;i++) cout << s[i];
    return 0;

}
