#include <bits//stdc++.h>
using namespace std;
map<char , int> idx;

int solve(string s)
{
    char temp=idx[s[0]];
    int res=0;
    for (int i=1;i<s.size();i++) res+=abs(idx[s[i]]-temp), temp=idx[s[i]];
    return res;

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q,dem=1; cin >> q;
    string s="abcdefghijklmnopqrstuvwxyz",x;
    for (char c : s) idx[c]=dem++;
    while (q--) cin >> x, cout << solve(x) << "\n";
    return 0;
}
