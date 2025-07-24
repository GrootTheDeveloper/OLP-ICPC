#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[1000006],cnt[1000006],n;
string s;
void sol1()
{
    int res=0;
    for (int i=1;i<=s.size();i++)
    {
        if (f[i]>=n)
            res+=(cnt[f[i]-n])+(f[i]-n==0);
    }
    cout << res; 
}
void sol2()
{
    int cnt=0,res=0;
    for (char c: s)
    {
        if (c=='0') cnt++;
        else cnt=0;
        res+=cnt;
    }
    cout << res;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s;
    for (int i=0;i<s.size();i++)
    {
        f[i+1]=f[i]+(s[i]-'0');
        cnt[f[i+1]]++;
    }
    if (n==0) sol2();
    else sol1();
    
}
