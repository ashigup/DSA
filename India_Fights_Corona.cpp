
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

void solve()
{
    ll a, b, n, q, m, p, x, s, z, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> egg(n);
    vector<ll> cost(n, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        a--;
        cost[a] = b;
        pq.push({b, a});
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        egg[a].push_back({c, b});
        egg[b].push_back({c, a});
    }
    while (!pq.empty())
    {
        ll u = pq.top().second;
        ll w = pq.top().first;
        pq.pop();
        if (w < cost[u])
            continue;
        for (auto vv : egg[u])
        {
            ll v = vv.second;
            ll t_w = vv.first;
            if (cost[v] > cost[u] + t_w)
            {
                cost[v] = cost[u] + t_w;
                pq.push({cost[v], v});
            }
        }
    }
    for (auto x : cost)
    {
        cout << x << " ";
    }
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