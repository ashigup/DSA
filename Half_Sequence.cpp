
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
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

const int MXN = 2e5 + 65;
ll v[MXN], d[MXN];
ll t[2 * MXN];
ll n;
bool comp1(vector<ll> a1, vector<ll> a2)
{
    if (a1[1] == a2[1])
        return a1[0] <= a2[0];
    return a1[1] <= a2[1];
}
void build()
{ // build the tree
    for (int i = n - 1; i > 0; --i)
        t[i] = __gcd(t[i << 1], t[i << 1 | 1]);
}
ll query(ll l, ll r) //value from [l,r)
{
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = __gcd(res, t[l++]);
        if (r & 1)
            res = __gcd(res, t[--r]);
    }
    return res;
}
void solve()
{
    ll a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n;
    vll d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    n--;
    f(i, 0, n)
        t[i + n] = abs(d[i] - d[i + 1]);
    build();
    auto check = [&](ll x)
    {
        if (x == 0)
            return false;
        f(i, 0, n - x + 1)
        {
            if (query(i, i + x) > 1)
                return true;
        }
        return false;
    };
    ll lo = 0, hi = n + 1;
    while (hi - lo > 1)
    {
        // deb(lo,hi)
        ll mid = (hi + lo) >> 1;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
    cout << lo + 1 << "\n";

    return;
}
int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        //cout << "\n";
    }
    return 0;
}