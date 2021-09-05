#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vs vector<string>
#define pll pair<ll, ll>
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
        vs arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == '#')
                    vis[i][j] = 1;
                else if (arr[i][j] == 'A')
                {
                    x = i;
                    y = j;
                }
            }
        }
        c = 0;
        queue<pair<ll, ll>> qq;
        qq.push({x, y});
        vis[x][y] = 1;
        map<pll, pll> par;
        pll start = {x, y}, end = {-1, -1};
        ll flag = 0;
        while (qq.size() > 0)
        {
            auto u = qq.front();
            qq.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = u.first + dx[i];
                int yy = u.second + dy[i];
                if (xx >= 0 && yy >= 0 && xx < arr.size() && yy < arr[0].size() && vis[xx][yy] == false)
                {
                    if (arr[xx][yy] == 'B')
                    {
                        end = {xx, yy};
                        flag = 1;
                    }
                    vis[xx][yy] = 1;
                    qq.push({xx, yy});
                    par[{xx, yy}] = u;
                }
            }
        }
        if (flag == 0)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        string path = "";
        while (end != start)
        {
            pll temp = par[end];
            if (temp.first == end.first)
            {
                if (temp.second < end.second)
                    path.push_back('R');
                else
                    path.push_back('L');
            }
            else
            {
                if (temp.first < end.first)
                    path.push_back('D');
                else
                    path.push_back('U');
            }
            end = temp;
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        cout << path;
        cout << "\n";
    }
    return 0;
}
