#include <bits/stdc++.h>
using namespace std;
bool nt(int n)
{
    if (n<=3) return n>1;
    if (n%2==0 || n%3==0) return false;
    int i=5;
    while (i*i <= n)
    {
        if (n%i==0 || n%(i+2)==0) return false;
        i+=6;
    }
    return true;
}
int main()
{
    int res=0;
    for (int i=1;i<=10000000;i++) if (nt(i)) res++;
    cout << res;
}
