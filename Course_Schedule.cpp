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
        vector<vector<ll>> egg(n);
        vll indeg(n, 0);
        for (int i = 0; i < e; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            egg[a].push_back(b);
            indeg[b]++;
        }
        //topological sort
        queue<ll> qq;
        vll ans;
        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 0)
                qq.push(i);
        }

        if (qq.size() == 0)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        while (!qq.empty())
        {
            ll u = qq.front();
            qq.pop();
            ans.push_back(u);
            for (auto v : egg[u])
            {
                indeg[v]--;
                if (indeg[v] == 0)
                    qq.push(v);
            }
        }
        //check cycle using topological sort
        map<ll, ll> pos;
        for (int i = 0; i < n; i++)
            pos[ans[i]] = i;
        ll flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int v : egg[i])
            {
                if (pos[i] > pos[v])
                {
                    flag = 1;
                }
            }
        }
        if (flag == 1)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        //print topological sort
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}