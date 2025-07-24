#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a, int b)
{
    return a>b;
}
vector <int> vi;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s; cin >> s;
    int cnt=0,sum=0;
    for (char c : s)
    {
        cnt+=(c=='0');
        sum+=c-'0';
        vi.push_back(c-'0');
    }
    if (cnt==0 || sum%3) {cout << -1;exit(0);}
    sort(vi.begin(),vi.end(),cmp);
    for (int i:vi) cout << i;

}
