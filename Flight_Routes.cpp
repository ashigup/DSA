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
        cin >> n >> m >> k;
        vector<vector<pll>> egg(n);
        map<pll, ll> edges;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            a--;
            b--;
            egg[a].push_back({c, b});
        }

        //dijkstra
        vll ans;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        vll dis(n, INF), vis(n, 0);
        pq.push({0, 0});
        while (pq.size() > 0)
        {
            auto node = pq.top();
            pq.pop();
            ll ind = node.second;
            // if (dis[ind] < node.first)
            //     continue;
            vis[ind]++;
            if (vis[ind] > k)
                continue;
            if (ind == n - 1)
            {
                ans.push_back(node.first);
            }
            for (auto v : egg[ind])
            {
                pq.push({node.first + v.first, v.second});
            }
        }
        // print
        for (auto xx : ans)
        {
            cout << xx << " ";
        }
    }
    return 0;
}