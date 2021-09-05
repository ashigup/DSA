#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
const ll INF = 1e17;
#define pll pair<ll, ll>
#define vll vector<ll>

int main()
{
    IOS;
    ll a, b, c, d, e, f, n, m, q, t, s;
    t = 1;
    //cin>>t;
    while (t--)
    {
        cin >> n >> e;
        vll dis(n, INF);
        vector<vector<pll>> egg(n);
        for (int i = 0; i < e; i++)
        {
            cin >> a >> b >> c;
            a--;
            b--;
            egg[a].push_back({c, b});
        }
        ll src = 0, end;
        dis[src] = 0;
        map<ll, ll> par;

        for (int i = 1; i <= n - 1; i++)
        {
            for (int u = 0; u < n; u++)
            {
                for (auto v : egg[u])
                {
                    if (dis[u] + v.first < dis[v.second])
                    {
                        dis[v.second] = dis[u] + v.first;
                        par[v.second] = u;
                    }
                }
            }
        }
        ll flag = 0;
        for (int u = 0; u < n; u++)
        {
            for (auto v : egg[u])
            {
                if (dis[u] + v.first < dis[v.second])
                {
                    flag = 1;
                    end = v.second;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 0)
        {
            cout << "NO\n";
            continue;
        }

        vector<ll> path;
        vll vis(n, 0);

        while (false == vis[end])
        {
            vis[end] = 1;
            end = par[end];
        }
        path.push_back(end);
        src = par[end];
        while (src != end)
        {
            path.push_back(src);
            src = par[src];
        }
        path.push_back(end);
        // reverse(path.begin(), path.end());
        cout << "YES\n";
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[path.size() - 1 - i] + 1 << " ";
        }

        cout << "\n";
    }
    return 0;
}