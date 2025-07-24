#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int dp[20][150];
int a[20];
int n;
bool cp[150];
int vec[1200000];
int lim;

void Try(int i, int x, int s)
{
    if (cp[s]) vec[++lim] = x;
    if (i > 19) return;
    Try(i + 1, x * 10 + 3, s + 3);
    Try(i + 1, x * 10 + 7, s + 7);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int i = 1; i * i < 150; i++) cp[i * i] = true;
    Try(1, 0, 0);
    sort(vec + 1, vec + lim + 1);
    while (t--)
    {
        int l, r; cin >> l >> r;
        int pos2 = upper_bound(vec + 1, vec + lim + 1, r) - vec;
        int pos1 = lower_bound(vec + 1, vec + lim + 1, l) - vec;
        cout << pos2 - pos1 << '\n';
    }

}



