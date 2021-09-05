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

        if (qq.size() == 0 || egg[0].size() == 0)
        {
            cout << "IMPOSSIBLE\n";
            continue;
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
        vll par(n, -1);
        for (int i : topoSorted)
        {
            for (auto v : egg[i])
            {
                if (dis[v] <= dis[i] + 1 && dis[i])
                {
                    dis[v] = dis[i] + 1;
                    par[v] = i;
                }
            }
        }

        if (dis[n - 1] == -1)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        // getting path for longest distance
        vll ans;
        ll start = 0, end = n - 1;
        ll flag = 0;
        ans.push_back(end);
        while (start != end)
        {
            ll temp = par[end];
            ans.push_back(temp);
            if (temp == -1)
                flag = 1;
            end = temp;
        }
        if (flag == 1)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        reverse(ans.begin(), ans.end());
        //print longest path
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}