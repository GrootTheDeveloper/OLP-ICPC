#include <bits/stdc++.h>
using namespace std;
unsigned long long ucln(int a,int b)
{
    if (b==0) return a;
    return ucln(b, a%b);
}
unsigned long long bcnn(int  a, int  b)
{
    return a/ucln(a,b)*b;
}
bool cp(unsigned long long n)
{
    if (sqrt(n)==(int)sqrt(n)) return 1;
    return 0;
}
int main()
{
    int a,b,c;
    unsigned long long k,p;
    cin >> a >> b >> c;
    k=bcnn(bcnn(a,b),c);
    p=k;
    while (!cp(p))
        p+=k;
    cout << (int)sqrt(p);


    return 0;
}

