#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
// #define infile cin
// #define outfile cout

void solve()
{
    ll x, n, y, k, c = mod, m1, m2, rr, cc;
    c = 0;
    string s1;
    cin >> n >> s1;
    k = -1;
    vector<ll> dp(n, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '1')
        {
            dp[i] = 0;
            k = i;
        }
        else
        {
            if (k != -1)
                dp[i] = i - k;
        }
    }
    k = -1;
    c = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s1[i] == '1')
        {
            dp[i] = 0;
            k = i;
        }
        else
        {
            if (k != -1)
                dp[i] = min(dp[i], k - i);
        }
        c += dp[i];
    }
    cout << c << "\n";
}
int main()
{

    ll t = 1, n, m, a, b;
    string s1;
    cin >> t;
    for (int t0 = 1; t0 <= t; t0++)
    {
        cout << "Case #" << t0 << ": ";
        solve();
    }
    return 0;
}
