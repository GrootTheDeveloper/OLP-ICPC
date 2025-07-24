#include <bits/stdc++.h>
using namespace std;


string T;
string a[2000005];
int n;

int f(string s1, string s2)
{
    int ans = 0;
    int len = s2.size();
    for (int i = 0; i <= (int)s1.size() - len; i++)
        ans += (s1.substr(i, len) == s2);
    return ans;
}

void sub1()
{
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
        ans += f(a[i] + a[j], T);
    cout << ans << ' ';
}

string PreT[30], SufT[30];

int total = 0;
int pre[30], suf[30];

void tag(string s)
{
    int len = T.size();
    int k = s.size();
    string p = "", sf = "";
    for (int i = 1; i <= min(len - 1, k); i++)
    {
        p = p + s[i - 1];
        sf = s[k - i] + sf;

        pre[i] += (sf == PreT[i]);
        suf[i] += (p  == SufT[i]);
    }
}

void add(string s, long long &ans)
{
    int len = T.size();
    int k = s.size();
    string p = "", sf = "";
    // int t1 = 0, t2 = 0;
    for (int i = 1; i <= min(len - 1, k); i++)
    {
        p = p + s[i - 1];
        sf = s[k - i] + sf;

        if (sf == PreT[i]) ans += suf[len - i];
        if (p  == SufT[i]) ans += pre[len - i];
    }
}
void sub2()
{

    int lenT = T.size();
    for (int i = 1; i < lenT; i++)
        PreT[i] = T.substr(0, i);
    for (int i = 1; i < lenT; i++)
        SufT[i] = T.substr(lenT - i, i);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = f(a[i], T);
        ans += 1ll * cnt * (i - 1) * 2;
        total += cnt;
        ans += 1ll * total * 2;
        add(a[i], ans);
        tag(a[i]);
        string st = a[i].substr(max(0, (int)a[i].size() - lenT + 1), lenT - 1) + a[i].substr(0, min((int)a[i].size(), lenT - 1));
        ans += f(st, T);
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    //sub1();
    sub2();
    

   
}
