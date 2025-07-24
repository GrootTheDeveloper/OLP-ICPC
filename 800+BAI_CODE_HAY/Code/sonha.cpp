#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define FOR(i,l,r) for(int i=l; i<=r; i++)
#define FOD(i,r,l) for(int i=r; i>=l; i--)
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<int, pii>
#define vii vector<pii>
#define viii vector<piii>
#define mod 1000000
#define inf 1e18
#define N 1000006
#define M 1003
#define pb push_back
using namespace std;
int a[10];
int cs(int n)
{
    int cnt = 0;
    while (n) cnt++, n /= 10;
    return cnt;
}
int solve(int n)
{
    int m = cs(n), p = pow(10, m-1) - 1, tmp = n - p;
    return (tmp * m + a[m-1]) * 1ll * 80000;
}
int power(int a, int b)
{
    int res = 1;
    for (int i = 1; i <= b; i++)
        res *= a;
    return res;
}
main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    FOR(i,1,9) a[i] = a[i-1] + 9 * (power(10, i-1)) * i;
    int q = 1;
    while (q--)
    {
        int n; cin >> n;
        int ans = solve(n);
        cout << ans << ' ';
    }
}
