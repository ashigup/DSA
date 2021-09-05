#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define pll pair<ll, ll>
const ll INF = 1e18;
int main()
{
    ll t = 1;
    //cin>>t;
    for (int t0 = 1; t0 <= t; t0++)
    {
        ll n, m, k, a, b, c;
        cin >> n >> m;
        vector<vector<pll>> egg(n);
        //map<pll, ll> edges;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            a--;
            b--;
            egg[a].push_back({c, b});
        }

        //bellman ford
        vll dis(n, -INF);
        dis[0] = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            for (int u = 0; u < n; u++)
            {
                if (dis[u] != -INF)
                {
                    for (auto v : egg[u])
                    {
                        if (dis[v.second] < dis[u] + v.first)
                        {
                            dis[v.second] = dis[u] + v.first;
                        }
                    }
                }
            }
        }
        ll flag = 0;

        for (int i = 1; i <= n - 1; i++)
        {
            for (int u = 0; u < n; u++)
            {
                if (dis[u] != -INF)
                {
                    for (auto v : egg[u])
                    {
                        if (dis[v.second] < dis[u] + v.first)
                        {
                            dis[v.second] = INF;
                        }
                    }
                }
            }
        }
        if (dis[n - 1] == INF)
            dis[n - 1] = -1;
        cout << dis[n - 1] << "\n";
    }
    return 0;
}