#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int a[3*N],l[3*N],r[3*N],n;

void buildL()
{
    priority_queue<int, vector<int> , greater<int> > c;
    for (int i=1;i<=n*2;i++)
    {
        l[i]=l[i-1]+a[i];
        c.push(a[i]);
        if (i<=n) continue;
        l[i]-=c.top();
        c.pop();
    }
}
void buildR()
{
    priority_queue<int> c;
    for (int i=3*n;i>n;i--)
    {
        r[i]=r[i+1]+a[i];
        c.push(a[i]);
        if (i>2*n) continue;
        r[i]-=c.top();
        c.pop();
    }
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1;i<=3*n;i++) cin >> a[i];
    buildL();buildR();
    int ans=INT_MIN;
    for (int i=n;i<=2*n;i++) ans=max(ans,l[i]-r[i+1]);
    cout << ans;
}
