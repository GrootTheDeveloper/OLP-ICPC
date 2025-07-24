#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
int dp[1111][1111];
vector <pair<int,int>> vec[1001];
pair<int,int>  par[1001][1001];

bool ss(string a, string b)
{
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i]) return a[i] > b[i];
}
bool sp(ii a, ii b)
{
    return a.fi > b.fi && a.se > b.se;
}

signed main()
{
   // cout << (int)'A' << ' ' << (int)'a';
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s1,s2; cin >> s1 >> s2;
    int m = s1.size(), n = s2.size();
    s1 = "#" + s1;
    s2 = "#" + s2;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (s1[i] != s2[j])
                dp[i][j] = max({dp[i-1][j], dp[i][j-1]});
            else dp[i][j] = dp[i-1][j-1] + 1, vec[dp[i][j]].emplace_back(i,j);
        }
    int lim = dp[m][n];

    for (int i = 1; i <= lim; i++)
        for (int j = 0; j < vec[i].size(); j++)
            par[i][j] = {-1,-1};
    for (int i = 0; i < vec[1].size(); i++) par[1][i] = {0,0};

    for (int i = 2; i <= lim; i++)
        for (int j = 0; j < vec[i].size(); j++)
        {
            char ans = 'A';
            for (int z = 0; z < vec[i - 1].size(); z++)
            if (sp(vec[i][j], vec[i-1][z]) && par[i-1][z].fi != -1 && ans < s1[vec[i-1][z].fi])
            {
                par[i][j] = {i-1,z};
                ans = s1[vec[i-1][z].fi];
            }
        }
    string res = "";
    for (int i = 0; i < vec[lim].size(); i++)
    {
        int x = lim, y = i;
        string s;
        while (x != 0)
        {
            s.push_back(s1[vec[x][y].fi]);
            ii k = par[x][y];
            x = k.fi; y = k.se;
        }
        reverse(s.begin(), s.end());
        if (ss(s,res)) res = s;
    }
    cout << res;


}
