#include <iostream>
using namespace std;

int ucln(int a, int b)
{
    if (b==0)
    {
        return a;
    }
    else
    {
        return ucln(b,a%b);
    }
}
int main()
{
    int m,n,t;
    freopen("VN.INP","r", stdin);
    freopen("VN.OUT","w", stdout);
    cin >> n >> m;
    t=ucln(n,m);
    cout << t << endl;
    cout << n/t << " " << m/t;
    return 0;

}
