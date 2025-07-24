#include <bits/stdc++.h>
using namespace std;
//#define int long long
int lim1, lim2;
int a[555], b[555];
int cnta[555], cntb[555], cnt1[26][555], cnt2[26][555];
string s1, s2;
void ex(string &s, int* cnt, int* a, int &lim)
{
    s.push_back('a');
    char cur;
    int val = 0;
    for (char x : s)
    {
        if (x >= 'a' && x <= 'z')
        {
            if (val != 0)
            {
                ++lim;
                cnt[lim] = val;
                a[lim] = cur - 'a';
                val = 0;
            }
            cur = x;
        }
        else val = val * 10 + (x - '0');
    }
//    for (int i = 1; i <= lim; i++)
//        for (int c = 'a'; c <= 'z'; c++)
//            for (int x = 'a'; x <= 'z'; x++)
//                coun[c][x][i] = coun[c][x][i - 1] + cnt[i] * (a[i] == x - 'a');
}
int dp1[555][555], dp2[555][555];
void solve1()
{

    for (int i = 1; i <= lim1; i++)
        for (int j = 1; j <= lim2; j++)
        if (a[i] == b[j])
        {
            //dp1[i][j] = min(cnta[i], cntb[j]);
            int s1 = 0;
            for (int pos1 = i; pos1 >= 0; pos1--)
            {
                int s2 = 0;
                for (int pos2 = j; pos2 >= 0; pos2--)
                {
                    if (a[pos1] == b[pos2])
                    {
                        if (cnta[pos1] == cntb[pos2]) dp1[i][j] = max(dp1[i][j], dp1[pos1][pos2] + min(s1, s2));
                        else dp1[i][j] = max(dp1[i][j], min(cnta[pos1], cntb[pos2]) + min(s1, s2));
                    }
                    s2 += cntb[pos2] * (b[pos2] == b[j]);
                }
                s1 += cnta[pos1] * (a[pos1] == a[i]);
            }
        }
    int ans = 0;
    for (int i = 1; i <= lim1; i++)
    {
        for (int j = 1; j <= lim2; j++)
            cout << dp1[i][j] << ' ';
        cout << '\n';
    }
    cout << ans;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s1 >> s2;
    ex(s1, cnta, a,lim1);
    ex(s2, cntb, b,lim2);
    solve1();

}



