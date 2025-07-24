#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int pos[2000005],n,k,m;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> s;
    n=s.size();
    for (int i=1;i<=n;i++) pos[i]=i;
    cin >> m;
    while (m--)
    {
        cin >> k;
        int l=n-k+1,r=k;
        while (l<r) swap(pos[l++],pos[r--]);
    }
    for (int i=1;i<=n;i++) cout << s[pos[i]-1];
}
void ....()
{

}
