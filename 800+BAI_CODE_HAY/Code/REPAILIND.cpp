#include <bits/stdc++.h>
using namespace std;

/*bool dx(string s)
{
    int k=s.size()-1;
    for (int i=0;i<=k/2;i++)
    {
        if (s[i]!=s[k-i]) return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        long long k;    cin >> k;
        if (dx(s)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}*/

#define int long long
const int N=1e5+5;
const int oo = 1e18 + 7;
int a[N*3],l[3*N],r[3*N],n;

void buildL()
{
    priority_queue<int,vector<int>,greater<int>> c;
    for (int i=1;i<=n*3;i++)
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
    for (int i=3*n;i>=1;i--)
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
    int res=-oo;
    for (int i=n;i<=2*n;i++)
        res=max(res,l[i]-r[i+1]);
    cout << res;
}































