#include <bits/stdc++.h>
using namespace std;
int n,a[2]={0,1};
vector <int> s;
void solve()
{
    for (int i=0;i<s.size();i++) cout << s[i];
    cout << endl;
}
void Try(int i)
{
    if (i==n+1) return solve(),void();
    for (int k : a)
    {
        s.push_back(k);
        Try(i+1);
        s.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    Try(1);

}
