#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){ if (b==0) return a; return gcd(b,a%b);}
bool check(int n)
{
    int res=0,temp=n;
    while (temp>0) res=res*10+temp%10, temp/=10;
    if (gcd(res,n)==1) return true;
    return false;
}

int main()
{
    int a,b;
    cin >> a >> b;
    int res=0;
    for (int i=a;i<=b;i++) if (check(i)) res++;
    cout << res;
    return 0;
}
