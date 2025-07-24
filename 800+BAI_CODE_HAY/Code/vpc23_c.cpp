#include <bits/stdc++.h>
using namespace std;
#define int long long
#define db double
vector <int> vi;
int a[55],b[55];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    db MAX=0.0;
    int x=0,y=0;
    for (int i=1;i<=n;i++)
    if ((db)(x+a[i])/(y+b[i])>=MAX) x+=a[i],y+=b[i],MAX=(db)x/y,vi.push_back(i);
    cout << vi.size() << endl;
    for (int i: vi) cout << i << ' ';
}
