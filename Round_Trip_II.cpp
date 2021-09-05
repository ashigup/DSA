#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define pll pair<ll, ll>
const ll INF = 1e15;
//cycle detection in Directed graph O(N*N)
bool cycleDetection(ll u, vector<vll> &egg, vector<bool> &vis, vll &path, ll par)
{
    vis[u] = 1;
    path.push_back(u);
    for (ll v : egg[u])
    {
        if (v == u)
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
    vis[u] = 0;
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
        vll indeg(n, 0);
        for (int i = 1; i <= e; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            egg[a].push_back(b);
            indeg[b]++;
            //egg[b].push_back(a);
        }
        //topological sort
        queue<ll> qq;
        vll topoSort;
        for (int i = 0; i < n; i++)
            if (indeg[i] == 0)
                qq.push(i);
        while (qq.size())
        {
            auto u = qq.front();
            qq.pop();
            topoSort.push_back(u);
            for (auto v : egg[u])
            {
                indeg[v]--;
                if (indeg[v] == 0)
                {
                    qq.push(v);
                }
            }
        }
        //
    }
    return 0;
}