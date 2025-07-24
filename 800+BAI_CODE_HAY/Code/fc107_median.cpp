#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int P = 200005;

int n;
pair<int, int > p[P];
int t[P];


void read()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> p[i].fi;
        p[i].se = i;
    }
}

void solve()
{
    sort(p + 1, p + n + 1);
    for(int i = 1; i<=n; i++)
    {
        if(n / 2 < i) t[p[i].se] = p[n / 2].fi;
        else t[p[i].se] = p[n / 2 + 1].fi;
    }
    for(int i=1; i<=n; i++) cout << t[i] << '\n';
}


int main()
{
//    freopen("median.inp","r",stdin);
//    freopen("median.out","w",stdout);
    read();
    solve();
}
