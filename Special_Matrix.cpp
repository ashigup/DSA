
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
ll funcc[2000005];
void solve()
{
    ll a, b, n, m, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> m;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += (funcc[m + 1 + i] - funcc[1 + i]);
        // cout << sum << "--";
    }
    cout << sum;
    return;
}
int main()
{
    ll t = 1;
    cin >> t;
    memset(funcc, 0, sizeof(funcc));
    for (int i = 2; i < 2000005; i++)
    {
        if (funcc[i] == 0)
        {
            funcc[i] = 1;
            for (int j = i + i; j < 2000005; j += i)
            {
                funcc[j]++;
            }
        }
    }
    for (int i = 1; i < 2000005; i++)
    {
        funcc[i] += funcc[i - 1];
    }
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}