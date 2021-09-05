#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
        s = 0;
        vector<ll> dis(n, INF);
        vector<bool> vis(n, false);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, s});
        dis[s] = 0;
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
                if (vis[v.second] == false && dis[v.second] > dis[ind] + v.first)
                {
                    dis[v.second] = dis[ind] + v.first;
                    pq.push({dis[v.second], v.second});
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << (dis[i]) << " ";
        }
        cout << "\n";
    }
    return 0;
}
