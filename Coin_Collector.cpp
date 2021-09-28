
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
void dfs(vector<vll> &egg, ll u, vll &vis, stack<ll> &st)
{
    vis[u] = 1;
    for (auto xx : egg[u])
    {
        if (vis[xx] == 0)
            dfs(egg, xx, vis, st);
    }
    st.push(u);
    //cout << u << " ";
}
void dfsStrong(vector<vll> &egg, ll u, vll &vis, vll &comp, ll label)
{
    vis[u] = 1;
    comp[u] = label;
    for (auto xx : egg[u])
    {
        if (vis[xx] == 0)
            dfsStrong(egg, xx, vis, comp, label);
    }
}

ll dfsSum(vector<vll> &egg, ll u, vll &dp, map<ll, ll> &grpCoins)
{
    if (dp[u] != -1)
        return dp[u];
    dp[u] = grpCoins[u];
    ll ans = 0;
    for (auto xx : egg[u])
    {
        dp[u] = max(dp[u], dfsSum(egg, xx, dp, grpCoins) + grpCoins[u]);
    }
    return dp[u];
}

void solve()
{
    ll a, b, n, q, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> m;
    vector<ll> coins(n, 0);
    vector<vll> egg(n), eggR(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        egg[a].push_back(b);
        eggR[b].push_back(a);
    }
    vll vis(n, 0);
    // topological sort / topoSort
    stack<ll> st;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(egg, i, vis, st);
        }
    }
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    vll comp(n, -1);
    ll label = 0;
    map<ll, ll> mxCoins;
    ll ans = 0;
    // grouped Strongly connected components
    while (!st.empty())
    {
        ll u = st.top();
        st.pop();
        if (vis[u] == 0)
        {
            label++;
            dfsStrong(eggR, u, vis, comp, label);
        }
    }
    // created value of each Strongly connected components
    for (int i = 0; i < n; i++)
    {
        mxCoins[comp[i]] += coins[i];
    }
    // creating a graph for Strongly connected components , we get DAG
    vector<vll> eggGroup(label + 1);
    for (int i = 0; i < n; i++)
    {
        for (auto xx : egg[i])
        {
            if (comp[xx] == comp[i])
                continue;
            eggGroup[comp[xx]].push_back(comp[i]);
        }
    }
    // now we can use dp to get the max value by a traversal
    vll dpSum(label + 1, -1);
    for (int i = 1; i <= label; i++)
    {
        ans = max(ans, dfsSum(eggGroup, i, dpSum, mxCoins));
    }
    cout << ans;
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