
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};
char dir[] = {'D', 'U', 'R', 'L'};
string ansStr = "";

ll dfs(ll x, ll y, vector<string> &arr, vector<vector<ll>> &dp, vector<vector<bool>> &vis, string &path)
{
    vis[x][y] = 1;
    if (x == 0 || y == 0 || x == arr.size() - 1 || y == arr[0].size() - 1)
        return 1;
    path.push_back('*');
    if (y + 1 < arr[0].size() && arr[x][y + 1] == '.' && !vis[x][y + 1] && path.size() + 1 < dp[x][y + 1] && dfs(x, y + 1, arr, dp, vis, path))
    {
        //path.pop_back();
        ansStr.push_back('R');
        return 1;
    }
    else if (x + 1 < arr.size() && arr[x + 1][y] == '.' && !vis[x + 1][y] && path.size() + 1 < dp[x + 1][y] && dfs(x + 1, y, arr, dp, vis, path))
    {
        //path.pop_back();
        ansStr.push_back('D');
        return 1;
    }
    else if (x - 1 >= 0 && arr[x - 1][y] == '.' && !vis[x - 1][y] && path.size() + 1 < dp[x - 1][y] && dfs(x - 1, y, arr, dp, vis, path))
    {
        //path.pop_back();
        ansStr.push_back('U');
        return 1;
    }
    else if (y - 1 >= 0 && arr[x][y - 1] == '.' && !vis[x][y - 1] && path.size() + 1 < dp[x][y - 1] && dfs(x, y - 1, arr, dp, vis, path))
    {
        //path.pop_back();
        ansStr.push_back('L');
        return 1;
    }
    path.pop_back();
    vis[x][y] = 0;

    return 0;
}
void solve()
{
    ll n, m, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //getting minimum
    a = b = -1;
    queue<pll> qq;
    vector<vector<ll>> dp(n, vector<ll>(m, INT_MAX));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'M')
            {
                dp[i][j] = 0;
                qq.push({i, j});
                vis[i][j] = 1;
            }
            else if (arr[i][j] == 'A')
            {
                x = i;
                y = j;
            }
        }
    }
    if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
    {
        cout << "YES\n0";
        return;
    }
    //cal min time for monster
    while (!qq.empty())
    {
        auto u = qq.front();
        qq.pop();
        for (int j = 0; j < 4; j++)
        {
            ll vx = u.first + dx[j];
            ll vy = u.second + dy[j];
            if (vx >= 0 && vx < n && vy >= 0 && vy < m && !vis[vx][vy] && arr[vx][vy] != '#' && dp[vx][vy] > dp[u.first][u.second] + 1)
            {
                dp[vx][vy] = dp[u.first][u.second] + 1;
                vis[vx][vy] = 1;
                qq.push({vx, vy});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = 0;
            if (!qq.empty())
                qq.pop();
        }
    }
    ansStr = "";
    // Starting from A

    qq.push({x, y});
    dp[x][y] = 0;
    vis[x][y] = 1;
    a = 0;
    ll found = 0;
    pair<ll, ll> end, start = {x, y};
    map<pll, pll> par;
    while (!qq.empty())
    {
        pll u = qq.front();
        qq.pop();
        for (int j = 0; j < 4; j++)
        {
            ll vx = u.first + dx[j];
            ll vy = u.second + dy[j];
            if (vx >= 0 && vx < n && vy >= 0 && vy < m && arr[vx][vy] != '#' && !vis[vx][vy] && dp[vx][vy] > dp[u.first][u.second] + 1)
            {
                if (vx == 0 || vy == 0 || vx == n - 1 || vy == m - 1)
                {
                    found = 1;
                    end = {vx, vy};
                    //break;
                }
                vis[vx][vy] = 1;
                dp[vx][vy] = dp[u.first][u.second] + 1;
                par[{vx, vy}] = u;
                qq.push({vx, vy});
            }
        }
        if (found == 1)
            break;
    }

    if (found == 0)
    {
        cout << "NO";
        return;
    }
    //Calc path
    ansStr = "";
    while (end != start)
    {
        pll temp = par[end];
        if (temp.first == end.first)
        {
            if (temp.second < end.second)
                ansStr.push_back('R');
            else
                ansStr.push_back('L');
        }
        else
        {
            if (temp.first < end.first)
                ansStr.push_back('D');
            else
                ansStr.push_back('U');
        }
        end = temp;
    }
    reverse(ansStr.begin(), ansStr.end());

    cout << "YES"
         << "\n";
    cout << ansStr.size() << "\n";
    cout << ansStr;
    return;
}
int main()
{
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "\n";
    }
    return 0;
}