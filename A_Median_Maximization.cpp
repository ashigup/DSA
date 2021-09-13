
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
    ll n, a, b, s, x, y, k, c = mod, m1, m2, rr, cc;
    cin >> n >> s;
    if (n % 2 == 0)
    {
        a = n / 2 + 1;
        c = s / a;
    }
    else
    {
        a = n / 2 + 1;
        c = s / a;
    }
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