#include <bits/stdc++.h>
using namespace std;
vector<int> vi;

bool check(int n)
{
    int x=n;
    while (x!=0)
    {
        int temp=x%10;
        if (temp==0 || n%temp!=0) return 0;
        x/=10;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int l,r; cin >> l >> r;
    for (int i=l;i<=r;i++) if (check(i)) vi.push_back(i);
    cout << vi.size() << endl;
    for (int i : vi) cout << i << ' ';
    return 0;
}
