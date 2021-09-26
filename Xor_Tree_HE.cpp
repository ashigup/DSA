
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
void dfs(ll u, ll p, vll &par, vector<vll> &egg)
{
    par[u] = p;
    for (ll v : egg[u])
    {
        if (v == p)
            continue;
        dfs(v, u, par, egg);
    }
}
vll tin, tout;
ll timer;
ll N, L;
vector<vll> up;
void calc_dfs(ll u, ll p, vector<vll> &egg)
{
    tin[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i <= L; i++)
    {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (auto &v : egg[u])
    {
        if (v == p)
            continue;
        calc_dfs(v, u, egg);
    }
    tout[u] = ++timer;
}
bool is_Ancestor(ll u, ll v)
{
    if (tin[u] <= tin[v] && tout[u] >= tout[v])
        return 1;
    return 0;
}
ll lca(ll u, ll v)
{

    if (is_Ancestor(u, v))
        return u;
    if (is_Ancestor(v, u))
        return v;
    for (int i = L; i >= 0; i--)
    {
        if (is_Ancestor(up[u][i], v))
        {
        }
        else
        {
            u = up[u][i];
        }
    }
    return up[u][0];
}
void preprocess(vector<vll> &egg)
{
    ll n = egg.size();
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    N = n - 1;
    L = ceil(log2(n));
    up.assign(n, vll(L + 1));
    calc_dfs(1, 0, egg);
}
void dfs2(ll u, ll p, vector<vll> &egg, ll z, vll &cost, ll c)
{
    if (u == z)
        return;
    cost[u] ^= c;
    for (auto v : egg[u])
    {
        if (v == p)
            continue;
        dfs2(v, u, egg, z, cost, c);
    }
}
void dfs3(ll u, ll p, vector<vll> &egg, vll &cost, ll c)
{
    for (auto v : egg[u])
    {
        if (v == p)
            continue;

        cost[v] ^= c;
        dfs3(v, u, egg, cost, c);
    }
}
bool dfs4(ll u, ll des, ll c, ll p, vector<vll> &egg, vll &cost)
{
    if (u == des)
        return 1;
    for (auto v : egg[u])
    {
        if (v == p)
        {
            continue;
        }
        if (dfs4(v, des, c, u, egg, cost))
        {
            cost[v] ^= c;
            return 1;
        }
    }

    return 0;
}
void solve()
{
    ll a, b, n, q, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> q;
    vector<vll> egg(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        egg[a].push_back(b);
        egg[b].push_back(a);
    }

    vll cost(n + 1, 0);
    vll par(n + 1, -1);
    dfs(1, 0, par, egg);
    ll ans = 0;
    s = 0;
    // preprocess(egg);
    while (q--)
    {
        cin >> a >> b >> c;
        // s ^= c;
        cost[a] ^= c;
        dfs4(a, b, c, par[a], egg, cost);
        // x = lca(a, b);
        // if (x >= 1)
        //     dfs2(1, 0, egg, x, cost, c);
        // if (is_Ancestor(a, b))
        // {
        //     dfs3(b, up[b][0], egg, cost, x);
        // }
        // else if (is_Ancestor(b, a))
        // {
        //     dfs3(a, up[a][0], egg, cost, x);
        // }
        // else
        // {
        //     dfs3(b, up[b][0], egg, cost, x);
        //     dfs3(a, up[a][0], egg, cost, x);
        // }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cost[i] ^= s;
    // }
    for (int i = 1; i <= n; i++)
    {
        ans += cost[i];
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