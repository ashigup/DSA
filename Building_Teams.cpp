#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vs vector<string>
#define pll pair<ll, ll>
#define vll vector<ll>
const ll INF = 1e15;
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};
void dfs1(vs &arr, ll x, ll y, vector<vector<bool>> &vis)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && yy >= 0 && xx < arr.size() && yy < arr[0].size() && vis[xx][yy] == false)
            dfs1(arr, xx, yy, vis);
    }
}
ll dfs(vector<vll> &egg, ll u, ll color, vector<bool> &vis, vll &team)
{
    vis[u] = 1;
    team[u] = color % 2;
    ll a = 1;
    for (ll v : egg[u])
    {
        if (vis[v] == false)
        {
            a = dfs(egg, v, color + 1, vis, team);
        }
        else
        {
            if (team[v] != ((color + 1) % 2))
                a = 0;
        }
        if (a == 0)
            return 0;
    }

    return 1;
}
int main()
{
    ll a, b, c, d, e, x, y, f, n, m, t, s;
    t = 1;
    //cin>>t;
    while (t--)
    {
        cin >> n >> m;
        vector<vll> egg(n);
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            egg[a].push_back(b);
            egg[b].push_back(a);
        }
        vector<bool> vis(n, 0);
        vector<ll> team(n, -1);
        ll flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == false)
            {
                flag = dfs(egg, i, 0, vis, team);
                if (flag == 0)
                    break;
            }
        }

        if (flag == 0)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            cout << team[i] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
