#include <bits/stdc++.h>
using namespace std;
#define int long long
bool prime[120], f1[1000000], f2[1000000];
int l,r,res;
bool check(int n)
{
    string s = to_string(n);
    int l = 0, r = s.size() - 1;
    int sum = 0;
    while (l < r && s[l] == s[r])
    {
        sum += 2 * (s[l] - '0');
        l ++;
        r --;
    }
    if (l < r) return false;
    if (l == r) sum += (s[l] - '0');
    return prime[sum];
}
int so(string num)
{
    int res = 0;
    for (auto x : num)
        res = res*10 + (x - '0');
    return res;
}

void sub1(int l, int r)
{
    int res = 0;
    for (int i = l; i <= r; i++) res += check(i);
    cout << res;
}
void Try(string num, int sum)
{
    int val = stoll(num);
    if (val > r || num.size() > 11) return;
    if (num[0] != '0' && val <= r && val >= l && prime[sum]) res++;
    for (int i = 0; i <= 9; i++)
    {
        Try(to_string(i) + num + to_string(i), sum + 2*i);
    }
}

void subll()
{
    for (int i = 1; i <= 9; i+=2)
        Try(to_string(i), i);

    string s ="";
    for (int i = 1; i <= 12; i++)
    {
        string st = "1" + s + "1";
        int val = stoll(st);
        if (val > r) break;
        if (val >= l) res++;//, f2[val] = true;
        s.push_back('0');
    }
    res += (l<=2);
    cout << res;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cin >> l >> r;
    l = 1; r = (int)1e12;
    for (int i = 2; i <= 110; i++) prime[i] = true;
    for (int i = 2; i*i <= 110; i++)
        if (prime[i]) for (int j = i * i; j <= 110; j+=i) prime[j] =false;

    subll();
    cout << '\n' << clock()/ (double)1000;
    //for (int i = l; i <= r; i++) if (f1[i] == true && f2[i] == false) cout << i << ' ';

}
