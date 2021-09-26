#include <bits/stdc++.h>
#include <vector>
#define ll long long int
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
const ll INF = 1e18;
void dijkstra(vector<vector<pair<ll, ll>>> &egg, vector<vector<ll>> &dist, ll src, ll k)
{
    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
    ll n = egg.size();
    pq.push({0, {src, 0}}); // dis,src,number of k used
    dist[src][0] = 0;

    while (!pq.empty())
    {
        ll u = pq.top().second.first;
        ll dis2u = pq.top().first;
        ll k_used = pq.top().second.second;
        pq.pop();
        if (dist[u][k_used] < dis2u)
            continue;
        for (auto vv : egg[u])
        {
            ll v = vv.first;
            ll cos = vv.second;
            if (dist[v][k_used] > dis2u + cos)
            {
                dist[v][k_used] = dis2u + cos;
                pq.push({dist[v][k_used], {v, {k_used}}});
            }
            if (k_used + 1 <= k && dist[v][k_used + 1] > dis2u)
            {
                dist[v][k_used + 1] = dis2u;
                pq.push({dist[v][k_used + 1], {v, {k_used + 1}}});
            }
        }
    }

    return;
}
int main()
{
    ll t;
    ios::sync_with_stdio(0), cin.tie(0);
    t = 1;
    //cin>>t;
    while (t--)
    {
        ll n, m, w, k, a, b;
        cin >> n >> m >> k;
        vector<vector<pair<ll, ll>>> egg(n);
        vector<vector<ll>> dist(n, vector<ll>(k + 1, INF));
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> w;
            a--;
            b--;
            egg[a].push_back({b, w});
            egg[b].push_back({a, w});
        }
        dijkstra(egg, dist, 0, k);

        for (int i = 0; i < n; i++)
            cout << *min_element(dist[i].begin(), dist[i].end()) << ' ';
    }
    return 0;
}
