
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
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> k >> s1;
    int prev1 = -1, prev0 = -1;
    vector<ll> dp(n, 0);
    c = 0;
    for (int i = 1; i < n; i++)
    {
        if (s1[i] != s1[i - 1])
        {
            c++;
            dp[i] = c;
        }
        else
        {
            dp[i] = c;
        }
    }
    if (dp[n - 1] < k)
    {
        cout << "-1";
        return;
    }
    char ch;
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        if (k - 1 == dp[i])
        {
            break;
        }
    }
    ch = s1[i];
    for (i = n - 1; i >= 0; i--)
    {
        if (s1[i] != ch)
        {
            cout << i + 1;
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