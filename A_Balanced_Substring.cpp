
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
ll modpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans % mod;
}
void solve()
{
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    cin >> n >> s1;
    c = 0;
    a = b = -1;
    map<ll, ll> mp;
    for (int i = 1; i < n; i++)
    {
        if (s1[i] != s1[i - 1])
        {
            a = i - 1 + 1;
            b = i + 1;
            break;
        }
    }

    cout << a << " " << b;
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