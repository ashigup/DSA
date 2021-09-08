
#define ll long long int
#include <bits/stdc++.h>
#define mod 998244353
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
    ll n, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2 = "YES";
    cin >> n;
    vector<ll> arr(n);
    map<ll, ll> mp;
    ll mx = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        mx = max(mx, arr[i]);
    }
    ll ans = 1;
    if (mp[mx] != 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            ans *= i;
            ans %= mod;
        }
    }
    else if (mp[mx - 1] == 0)
    {
        ans = 0;
    }
    else
    {
        ans *= mp[mx - 1];
        ans %= mod;
        for (int i = 1; i <= mp[mx - 1]; ++i)
        {
            ans *= i;
            ans %= mod;
        }
        ll lft = n - 1 - mp[mx - 1];
        ll val = 1 + mp[mx - 1] + 1;
        for (int i = 0; i < lft; ++i)
        {
            ans *= (val + i);
            ans %= mod;
        }
    }

    cout << ans;
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