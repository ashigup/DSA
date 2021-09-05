#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vs vector<string>
#define pll pair<ll, ll>
#define vll vector<ll>
const ll INF = 1e15;
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};
void dfs(vs &arr, ll x, ll y, vector<vector<bool>> &vis)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && yy >= 0 && xx < arr.size() && yy < arr[0].size() && vis[xx][yy] == false)
            dfs(arr, xx, yy, vis);
    }
}
int main()
{
    ll a, b, c, d, e, x, y, f, n, m, t, s;
    t = 1;
    //cin>>t;
    while (t--)
    {
        cin >> n >> m;
        vector<vll> egg(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            egg[a].push_back(b);
            egg[b].push_back(a);
        }
        vector<bool> vis(n, 0);
        c = 0;
        queue<ll> qq;
        qq.push(1);
        vis[1] = 1;
        unordered_map<ll, ll> par;
        ll start = 1, end = n;
        ll flag = 0;
        while (qq.size() > 0)
        {
            auto u = qq.front();
            qq.pop();
            for (ll v : egg[u])
            {
                if (vis[v] == false)
                {
                    if (v == n)
                    {
                        flag = 1;
                    }
                    par[v] = u;
                    vis[v] = 1;
                    qq.push(v);
                }
            }
        }
        if (flag == 0)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        // cout << "YES\n";
        vector<ll> path;
        path.push_back(n);
        while (end != start)
        {
            ll temp = par[end];
            path.push_back(temp);
            end = temp;
        }
        cout << path.size() << "\n";
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
