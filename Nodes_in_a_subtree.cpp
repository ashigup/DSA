
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define vii vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
//farthest Node in a Tree from u is a1
void farthestNode(int u, int p, vector<vll> &egg, vll &lev, ll &a1)
{
    lev[u] = lev[p] + 1;
    if (lev[a1] <= lev[u])
    {
        a1 = u;
    }
    for (auto v : egg[u])
    {
        if (v == p)
            continue;
        farthestNode(v, u, egg, lev, a1);
    }
}
void dfs(int u, int p, vector<vll> &egg, vector<vll> &dp)
{
    for (auto v : egg[u])
    {
        if (v == p)
            continue;
        dfs(v, u, egg, dp);
        for (int i = 0; i < 26; i++)
        {
            dp[u][i] += dp[v][i];
        }
    }
}
void solve()
{
    ll a, b, n, q, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> q >> s1;
    m = n - 1;
    vector<vll> egg(n + 1), eggR(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        egg[a].push_back(b);
        egg[b].push_back(a);
        // eggR[b].push_back(a);
    }
    // vll vis(n + 1, 0), lev(n + 1, -1);
    char ch;
    vector<vector<ll>> dp(n + 1, vector<ll>(26, 0));
    for (int i = 0; i < n; i++)
        dp[i + 1][s1[i] - 'a'] = 1;
    dfs(1, 0, egg, dp);
    while (q--)
    {
        cin >> a >> ch;
        cout << dp[a][ch - 'a'] << "\n";
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}