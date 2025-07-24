#include <bits/stdc++.h>
using namespace std;
#define int long long 
string s,st;
vector <int> pos[256];
int f[100005];


bool check(int x, int y)
{
    int l=x,r=y;
    while (l<r)
    {
        int mid=(l+r)/2;
        int lef=(mid+l)/2,rig=(mid+r)/2;
        if (s[mid]!=st[mid-x] || s[lef]!=st[lef-x] || s[rig]!=st[rig-x]) return false;
        r=mid-1;
    }
    l=x,r=y;
    while (l<r)
    {
        int mid=(l+r)/2;
        int lef=(mid+l)/2,rig=(mid+r)/2;
        if (s[mid]!=st[mid-x] || s[lef]!=st[lef-x] || s[rig]!=st[rig-x]) return false;
        l=mid+1;
    }
    return true;
}
void solve()
{
    int sum=0,n=st.size()-1;
    for (char c : st) sum+=(int)c;
    char first=st[0],last=st.back();
    for (int c : pos[(int)first])  
    {
        if (c+n>=s.size()) break;
        if (s[c+n]==last && f[c+n+1]-f[c]==sum)  
            if (check(c,c+n)) return cout << c+1 << '\n',void();
    }
    cout << -1 << '\n';
}


main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> s;
    for (int i=1;i<=s.size();i++) 
    {
        f[i]=f[i-1]+(int)s[i-1];
        pos[(int)s[i-1]].push_back(i-1);
    }

    int n; cin >> n;
    while (n--)
    {
        cin >> st;
        solve();
    }
}