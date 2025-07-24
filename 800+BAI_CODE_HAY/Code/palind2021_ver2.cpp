#include <bits/stdc++.h>
using namespace std;
struct dta{int fi,se;};
vector <dta> vi;
vector <dta> f;
vector <dta> o;
string s;
dta ss(dta a, dta b)
{
    if (a.se-a.fi==b.se-b.fi)
    {
        if (s[a.fi]-'0'>s[b.fi]-'0') return a;
    }
    if (a.se-a.fi>b.se-b.fi) return a;
    return b;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> s;
    int n=s.size();
    dta res; res.fi=0; res.se=0;
    for (int i=0;i<s.size();i++)
    {
        dta x;
        x.fi=x.se=i;
        vi.push_back(x);
        if (x.se+1!=n && s[x.fi]==s[x.se+1]) x.se++,vi.push_back(x);
    }
    while(vi.size())
    {
        for (dta c: vi)
        {
            if (c.fi-1>=0 && c.se+1!=n && s[c.fi-1]==s[c.se+1]) c.fi--,c.se++,f.push_back(c);
            else if (s[c.fi!='0'] && s[c.se!='0']) res=ss(res,c);
        }
        vi=(f);
        f=(o);
    }
    while (s[res.fi]=='0' && res.fi!=res.se) res.fi++,res.se--;
    cout << res.se-res.fi+1 << endl;
    for (int i=res.fi;i<=res.se;i++) cout << s[i];

}
