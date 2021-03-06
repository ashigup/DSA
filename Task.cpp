
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

bool comp1(vector<ll> a1, vector<ll> a2)
{
    if (a1[1] == a2[1])
        return a1[0] <= a2[0];
    return a1[1] <= a2[1];
}

void solve()
{
    ll a, b, n, q, m, p, x, s, z, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> k;
    ll ans = 0;
    for (int zz = 1; zz <= n - 2; zz++)
    {
        x = y = z = zz;
        for (int a = 0; a <= n - zz - zz; a++)
        {
            y = zz + a;
            x = n - zz - zz - a;
            if (x >= y && (x - y - z) > k)
            {
                ans++;
            }
        }
    }
    cout << ans;
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