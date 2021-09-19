#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define mpq priority_queue<ll, vector<ll>, greater<ll>>
// #define infile cin
// #define outfile cout
const ll INF = 1e18;
ll N, K;

bool check(vll a, ll curr)
{
    return (curr >= a[0] && curr <= a[1]);
}
bool comp(vector<ll> &a, vector<ll> &b)
{
    return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
}

ll fun(ll u, vector<vector<ll>> &v, vector<vector<ll>> &egg, ll curr, vector<ll> &dp, vector<ll> &vis)
{
    if (curr == K)
        return 1;
    if (curr > K)
        return 0;
    if (dp[u] != -1)
        return dp[u];
    ll ans = 0, tp;
    for (ll i = 0; i < N; i++)
    {
        bool flag = check(v[i], curr);
        if ((u >> i) & 1)
        {
        }
        else if ((!u) || (flag && vis[i]))
        {
            for (auto it : egg[i])
            {
                vis[it] += 1;
            }
            tp = u | (1 << i);
            ans += fun(tp, v, egg, curr + v[i][2], dp, vis);
            for (auto it : egg[i])
            {
                vis[it]--;
            }
        }
    }
    return dp[u] = ans;
}
void solve()
{
    ll x, n, m, d, a, b, y, k, c = mod, m1, m2, rr, cc;
    c = 0;
    string s1;
    cin >> n >> m >> k;
    N = n;
    K = k;
    vector<vector<ll>> prop, egg(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        prop.push_back({a, b, c});
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        egg[a].push_back(b);
        egg[b].push_back(a);
    }
    ll siz = 1 << (n + 1);
    vll dp(siz, -1), vis(n + 1, 0);
    ll ans = fun(0, prop, egg, 0, dp, vis);
    cout << ans << endl;
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
