
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
    cin >> n;
    cin >> x >> y;
    vector<pll> arr(n);
    a = b = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        a += arr[i].first;
        b += arr[i].second;
    }
    if (a < x || b < y)
    {
        cout << -1;
        return;
    }
    sort(arr.rbegin(), arr.rend());
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, -1));
    vector<vector<ll>> dp1(n + 1, vector<ll>(y + 1, -1));

    vector<vector<ll>> dp2(x + 1, vector<ll>(y + 1, INT_MAX));
    dp2[0][0] = 0;
    a = n;
    // a = min(a, fun(n, x, y, arr, dp));
    // for (int i = 0; i < n; i++)
    //     swap(arr[i].first, arr[i].second);
    // sort(arr.rbegin(), arr.rend());
    // a = min(a, fun(n, y, x, arr, dp1));

    for (auto num : arr)
    {
        int ones = num.first;
        int zeros = num.second;
        dp2[ones][zeros] = 1;
        for (int i = x; i >= 0; i--)
        {
            for (int j = y; j >= 0; j--)
            {
                if (i - zeros >= 0 && j - ones >= 0)
                    dp2[i][j] = min(dp2[i][j], 1 + dp2[i - zeros][j - ones]);
            }
        }
    }
    a = min(a, dp2[x][y]);
    cout << a;
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