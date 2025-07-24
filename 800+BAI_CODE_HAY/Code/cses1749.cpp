#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5;

int n, p, a[maxN+1];
tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> Tree;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        Tree.insert(i);
    }
    for (int i=1;i<=n;i++)
    {
        cin >> p;
        cout << a[*Tree.find_by_order(p-1)] << ' ';
        Tree.erase(*Tree.find_by_order(p-1));
    }
    return 0;

}

