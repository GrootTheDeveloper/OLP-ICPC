#include <bits/stdc++.h>
using namespace std;
string s;
int low[10]={0, 1, 0, 0, 0, 0, 0, 2, 0, 1},
     sum[10]={2,7,2,3,3,4,2,5,1,2},
     cnt[10]={6,2,5,5,4,5,6,3,7,6},
     f[20];
void sol1()
{
    int res=0;
    for (char c:s) res+=cnt[c-'0'];
    cout << res;
}
void sol2()
{
    int res=1;
    for (char c : s) res=res*sum[c-'0']-low[c-'0'];
    res--;
    cout << res;


}
main()
{
    int t;cin >> t;
    cin >> s;
    if (t==1) sol1();
    else sol2();
}
