#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define pll pair<ll, ll>
const ll INF = 1e15;
bool cycleDetection(ll u, vector<vll> &egg, vector<bool> &vis, vll &path, ll par)
{
    vis[u] = 1;
    path.push_back(u);
    for (ll v : egg[u])
    {
        if (v == par)
        {
            continue;
        }
        else if (vis[v] == false)
        {
            if (cycleDetection(v, egg, vis, path, u))
                return 1;
        }
        else if (vis[v] == true)
        {
            path.push_back(v);
            return 1;
        }
    }
    path.pop_back();
    return 0;
}
int main()
{
    ll a, b, c, d, e, f, n, m, t, s;
    t = 1;
    //cin>>t;
    while (t--)
    {
        cin >> n >> e;
        vector<vector<ll>> egg(n);
        for (int i = 1; i <= e; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            egg[a].push_back(b);
            egg[b].push_back(a);
        }
        vector<ll> path;
        vector<bool> vis(n, false);
        a = 0;
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == false)
            {
                flag = cycleDetection(i, egg, vis, path, -1);
                if (flag)
                    break;
            }
        }

        if (flag == false)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        c = 0;
        for (int i = 0; i < n; i++)
            vis[i] = 0;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            c++;
            if (vis[path[i]])
            {
                break;
            }
            vis[path[i]] = 1;
        }
        cout << c;
        cout << "\n";
        for (int i = 0; i < c; i++)
        {
            cout << path[path.size() - 1 - i] + 1 << " ";
        }
        // ll start = 0, end = n - 1;
        // while (end != start)
        // {
        //     auto temp = par[end];
        //     c = min(c, dis[n - 1] - temp.second + (temp.second / 2));
        //     ans.push_back(temp.first);
        //     end = temp.first;
        // }
    }
    return 0;
}