#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
const ll INF = 1e18;
#define pll pair<ll, ll>
#define vll vector<ll>

int main()
{
    IOS;
    ll a, b, c, d, e, f, n, m, q, t, s;
    t = 1;
    //cin>>t;
    cin >> n >> e >> t;
    vector<vll> dis(n, vll(n, INF));
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = dis[a][b];
    }
    for (int i = 0; i < n; i++)
        dis[i][i] = 0;
    for (int k = 0; k < n; k++)
    {
        for (ll s = 0; s < n; s++)
        {
            for (ll e = 0; e < n; e++)
            {
                if (dis[s][k] != INF && dis[k][e] != INF && dis[s][e] > dis[s][k] + dis[k][e])
                {
                    dis[s][e] = min(dis[s][e], dis[s][k] + dis[k][e]);
                }
            }
        }
    }
    while (t--)
    {
        cin >> a >> b;
        a--;
        b--;
        cout << (dis[a][b] == INF ? -1 : dis[a][b]);
        cout << "\n";
    }
    return 0;
}