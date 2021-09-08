
#define ll long long int
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define pbds tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
// using namespace __gnu_pbds;
#define mod 1000000007
using namespace std;
#define vll vector<ll>
vector<ll> xors(300005, 0);
void solve()
{
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    cin >> a >> b;
    c = a;
    x = xors[a - 1];
    b = b ^ x;
    if (b == a)
    {
        c += 2;
    }
    else if (b != 0)
        c++;
    cout << c;
    return;
}
int main()
{
    ll t = 1;
    cin >> t;
    for (int i = 1; i < 300005; i++)
        xors[i] = xors[i - 1] ^ i;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}