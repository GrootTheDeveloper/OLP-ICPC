#include <bits/stdc++.h>
using namespace std;
#define int long long
int count1,count2;
int a[30],b[30];
void add(int val) {a[val]++;count1+=(a[val]==1);}
void del(int val) {b[val]--;count2-=(b[val]==0);}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s; cin >> s;
    for (char c : s) b[c-'a']++;
    for (int i=0;i<=25;i++) count2+=(b[i]!=0);
    int res=0;
    for (char c : s)
    {
        add(c-'a');
        del(c-'a');
        res=max(res,count1+count2);
    }
    cout << res;


}
