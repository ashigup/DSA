
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
#define pll pair<ll, ll>
#define vll vector<ll>
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
map<char, int> cpppp;
bool comp1(string &s1, string &s2)
{
    int n = min(s1.size(), s2.size());
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
            return cpppp[s1[i]] < cpppp[s2[i]];
    }
    return (s1.size() <= s2.size());
}

ll fun(ll n, ll x, ll y, vector<pll> &arr, vector<vll> &dp)
{
    if (x <= 0)
    {
        if (y <= 0)
            return 0;
        return INT_MAX;
    }

    if (n == 0)
    {
        return INT_MAX;
    }
    if (dp[n][x] != -1)
        return dp[n][x];
    ll a = fun(n - 1, x, y, arr, dp);
    ll b = fun(n - 1, x - arr[n - 1].first, y - arr[n - 1].second, arr, dp) + 1;

    return dp[n][x] = min(a, b);
}
void solve()
{
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    vector<vll> arr(4, vector<ll>(4));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vll> dp(4, vector<ll>(4, 0));
    for (int i1 = 0; i1 < 16; i1++)
    {
        for (int i =)
            for (int i2 = 0; i2 < 16; i2++)
            {
                for (int i3 = 0; i3 < 16; i3++)
                {
                    for (int i4 = 0; i4 < 16; i4++)
                    {
                    }
                }
            }
    }

    return;
}
int main()
{
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}