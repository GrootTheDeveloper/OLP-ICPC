#include <bits/stdc++.h>
using namespace std;
ifstream fi ("anhem.inp");
ofstream fo ("anhem.out");

bool nt(int n)
{
    if (n<2)
        return 0;
    for (int i=2;i<=sqrt(n);i++)
        if (n%i==0)
            return 0;
    return 1;
}
bool ae(long long n)
{
    int t=0,s=0;
    while (n!=0)
    {
        t=t+n%10;
        s=s+pow(n%10,2);
        n/=10;
    }
    if (nt(t) and nt(s))
        return 1;
    else
        return 0;
}
int main()
{
    int L,R,d=0;
    fi >> L >> R;
    for (int i=L;i<=R;i++)
        if (ae(i))
            d+=1;
    fo << d;
    return 1;

}

