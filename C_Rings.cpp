
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
    string s1, s2;
    cin >> n >> s1;
    c = 0;
    for (int i = 0; i < n; i++)
    {
        c += (s1[i] - '0');
    }
    if (c == n)
    {
        cout << 1 << " " << n - 1 << " " << 2 << " " << n;
        return;
    }
    a = n / 2;
    b = a + 1;
    for (int i = a; i < n; i++)
    {
        if (s1[i] == '0')
        {
            cout << 0 + 1 << " " << 0 + i + 1 << " " << 0 + 1 << " " << 0 + i - 1 + 1;
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '0')
        {
            cout << i + 1 << " " << n << " " << i + 1 + 1 << " " << n;
            return;
        }
    }
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