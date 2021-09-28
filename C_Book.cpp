
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
const ll INF = 1e18;
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
bool dfs_cycle(ll u, ll p, vector<vll> &egg, vll &vis)
{
    vis[u] = 1;
    for (auto v : egg[u])
    {
        if (v == p)
            continue;
        if (vis[v] == 1)
            return 1;
        if (dfs_cycle(v, u, egg, vis) == true)
            return 1;
    }
    return 0;
}
ll dfs(ll u, ll p, vector<vll> &egg, vll &cost, vll &vis)
{

    if (cost[u] != -1)
    {
        return cost[u];
    }
    vis[u] = 1;
    ll ans = -1;
    for (auto v : egg[u])
    {
        if (v == p)
            continue;
        ll wei = (v > u ? 1 : 0);
        ans = max(ans, dfs(v, u, egg, cost, vis) + wei);
    }
    return cost[u] = ans;
}
ll topoSort(vector<vll> &egg)
{
    ll n = egg.size();
    vll indeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (ll xx : egg[i])
        {
            indeg[xx]++;
        }
    }
    priority_queue<ll, vll, greater<ll>> qq;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            qq.push(i);
        }
    }
    ll count = 0, ans = 0;
    while (!qq.empty())
    {
        set<ll> se;
        ans++;
        while (!qq.empty())
        {
            ll u = qq.top();
            qq.pop();
            count++;
            for (ll v : egg[u])
            {
                indeg[v]--;

                if (indeg[v] == 0)
                {
                    if (v > u)
                        qq.push(v);
                    else
                        se.insert(v);
                }
            }
        }
        for (auto xx : se)
            qq.push(xx);
    }
    if (count != n)
        ans = -1;
    return ans;
}
void solve()
{
    ll a, b, n, q, m, p, x, s, z, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n;
    ll ans = 0;
    vector<vector<ll>> egg(n); // transp_E(n);
    // vll vis(n, 0), cost(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> a;
            a--;
            egg[a].push_back(i);
        }
        //sort(egg[i].begin(), egg[i].end());
    }
    ans = topoSort(egg);
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