#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vs vector<string>
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
    ll a, b, c, d, e, f, n, m, t, s;
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
            }
        }
        c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == false)
                {
                    c++;
                    dfs(arr, i, j, vis);
                }
            }
        }
        cout << c;
        cout << "\n";
    }
    return 0;
}
