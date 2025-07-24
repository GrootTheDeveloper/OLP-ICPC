#include <bits/stdc++.h>
using namespace std;
int f[111];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for (int i=1;i<=105;i++) f[i]=1;
    int n,d; cin >> n >> d;
    while (n--)
    {
        string s; cin >> s;
        for (int i=0;i<s.size();i++)
            if (s[i]=='x') f[i+1]=0;
    }
    int res=0;
    for (int i=1;i<=d;i++)
        if (f[i]) f[i]+=f[i-1],res=max(res,f[i]);
    return cout << res,0;
}
