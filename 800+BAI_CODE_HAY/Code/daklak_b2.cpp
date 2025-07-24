#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cnt[10];
bool nt(int n)
{
    if (n<2) return false;
    for (int i=2;i<=sqrt(n);i++) if (n%i==0) return false;
    return true;
}
main()
{
    string s; cin >> s;
    int dem=0;
    for (char c : s) if (nt(c-'0') && !cnt[c-'0']) cout << c << ' ',cnt[c-'0']=true,dem++;
    if (dem==0) cout << dem;
}
