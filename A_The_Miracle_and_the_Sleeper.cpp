
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
void solve()
{
    ll n, m, a, l, r, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    cin >> l >> r;
    c = 0;
    if (l * 2 > r)
        c = r - l;
    else
        c = (r - 1) / 2;
    cout << c;
    return;
}
int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}