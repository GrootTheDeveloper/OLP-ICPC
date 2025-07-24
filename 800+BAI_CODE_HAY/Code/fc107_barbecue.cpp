#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
int C[4002][4002];
int a[200005], b[200005], n;
void add(int &a, int b)
{
    a += b;
    if (a > mode) a -= mode;
}
void init()
{
    for (int i = 1; i <= 4000; i++)
        C[i][i] = C[i][0] = 1;
    for (int i = 1; i <= 4000; i++)
        for (int j = 1; j < i; j++)
            add(C[i][j], C[i - 1][j - 1] + C[i - 1][j]);
}

void sub1()
{
    init();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
    {
        int A = a[i] + a[j], B = b[i] + b[j];
        add(ans, C[A + B][A]);
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    if (n <= 2000) sub1();
}
