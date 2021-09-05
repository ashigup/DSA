#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
const ll INF = 1e15;
#define pll pair<ll, ll>
#define vll vector<ll>
#define mod 1000000007

int main()
{
    IOS;
    ll a, b, c, d, e, f, n, m, q, t, s;
    t = 1;
    //cin>>t;
    while (t--)
    {
        cin >> n >> e;
        vector<set<ll>> egg(n);
        vll indeg(n, 0);
        for (int i = 0; i < e; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            if (egg[a].find(b) == egg[a].end())
            {
                egg[a].insert(b);
                indeg[b]++;
            }
        }
        //topological sort
        queue<ll> qq;
        vll topoSorted;
        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 0)
                qq.push(i);
        }

        while (!qq.empty())
        {
            ll u = qq.front();
            qq.pop();
            topoSorted.push_back(u);
            for (auto v : egg[u])
            {
                indeg[v]--;
                if (indeg[v] == 0)
                    qq.push(v);
            }
        }
        // longest distance from source to all other nodes
        vll dis(n, 0);
        dis[0] = 1;
        //vll par(n, -1);
        for (int i : topoSorted)
        {
            for (auto v : egg[i])
            {
                dis[v] += dis[i];
                dis[v] %= mod;
            }
        }
        cout << dis[n - 1];
        cout << "\n";
    }
    return 0;
}