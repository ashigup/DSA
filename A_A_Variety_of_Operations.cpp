
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>

void solve()
{
    ll n, m, a, l, r, b, x, y, k, c, d, m1, m2, rr, cc;
    string s1;
    cin >> c >> d;
    a = b = 0;
    if ((c + d) % 2 == 1)
    {
        cout << -1;
        return;
    }

    x = (c + d) / 2;
    if (c == 0 && d == 0)
        c = 0;
    else
    {
        if (x == c)
            c = 1;
        else
            c = 2;
    }

    cout << c;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}