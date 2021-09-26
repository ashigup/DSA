
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

ll solve(ll n, ll k, vll &wei, vll &tast)
{
    set<pair<ll, ll>> se;
    vll dp(n, n);
    vll sol = tast;
    for (ll i = 0; i < k; i++)
    {
        se.insert({wei[i], i});
    }
    for (int i = 0; i < n; i++)
    {
        se.erase({wei[i], i});
        if (i + k < n)
            se.insert({wei[i + k], i + k});
        if (se.size() > 0)
            dp[i] = se.rbegin()->second;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        sol[i] = max(sol[i], (dp[i] < n ? sol[dp[i]] + tast[i] : tast[i]));
    }
    ll ans = 0;
    for (auto x : sol)
        ans = max(ans, x);
    return ans;
}
int main()
{
    ll t = 1, n, k;
    cin >> t;
    while (t--)
    {

        cin >> n >> k;
        vll wei(n), tast(n);
        for (int i = 0; i < n; i++)
            cin >> wei[i];
        for (int i = 0; i < n; i++)
            cin >> tast[i];
        ll ans = solve(n, k, wei, tast);
        cout << ans << "\n";
    }
    return 0;
}