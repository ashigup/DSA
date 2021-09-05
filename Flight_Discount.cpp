#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pll pair<ll, ll>
const ll INF = 1e15;
int main()
{
    ll a, b, c, d, e, f, n, m, t, s;
    t = 1;
    //cin>>t;
    while (t--)
    {
        cin >> n >> e;
        vector<vector<ll>> v1;
        vector<vector<pair<ll, ll>>> egg(n);
        for (int i = 1; i <= e; i++)
        {
            cin >> a >> b >> c;
            a--;
            b--;
            egg[a].push_back({c, b});
            //egg[b].push_back({c,a});
        }
        //dijkstra Algorithm and dp
        vector<ll> dis(n, INF);
        vector<ll> dishalf(n, INF);
        vector<bool> vis(n, false);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        map<ll, pll> par;
        pq.push({0, 0});
        dis[0] = 0;
        dishalf[0] = 0;
        while (pq.size() > 0)
        {
            auto node = pq.top();
            pq.pop();
            int ind = node.second;
            if (vis[ind] == true)
            {
                continue;
            }
            vis[ind] = 1;
            for (auto v : egg[ind])
            {
                if (vis[v.second] == false)
                {
                    ll pos = 0;
                    //No coupon used till before and not now
                    if (dis[v.second] > dis[ind] + v.first)
                    {
                        dis[v.second] = dis[ind] + v.first;
                        pos = 1;
                        par[v.second] = {ind, v.first};
                    }
                    //Coupon used till before and not now
                    if (dishalf[v.second] > dishalf[ind] + v.first)
                    {
                        dishalf[v.second] = dishalf[ind] + v.first;
                        pos = 1;
                        par[v.second] = {ind, v.first};
                    }
                    //No coupon used till before and used now
                    if (dishalf[v.second] > dis[ind] + (v.first / 2))
                    {
                        dishalf[v.second] = dis[ind] + (v.first / 2);
                        pos = 1;
                        par[v.second] = {ind, v.first / 2};
                    }

                    if (pos == 1)
                    {
                        pq.push({dishalf[v.second], v.second});
                    }
                }
            }
        }
        c = min(dis[n - 1], dishalf[n - 1]);
        cout << c;
        cout << "\n";
        // ll start = 0, end = n - 1;
        // vector<ll> ans;
        // while (end != start)
        // {
        //     auto temp = par[end];
        //     c = min(c, dis[n - 1] - temp.second + (temp.second / 2));
        //     ans.push_back(temp.first);
        //     end = temp.first;
        // }
        // for (int i = 0; i < ans.size(); i++)
        // {
        //     cout << ans[i] << " ";
        // }
    }
    return 0;
}