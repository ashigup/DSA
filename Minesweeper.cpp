
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define vll vector<ll>
ll dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
ll dy[] = {-1, 0, 1, -1, 0, 1, 1, -1};
void bfs(int x, int y, vector<string> &arr, vector<vector<bool>> &vis)
{

    for (int k = 0; k < 8; k++)
    {
        ll xx = x + dx[k];
        ll yy = y + dy[k];
        if (xx >= 0 && yy >= 0 && xx < arr.size() && yy < arr.size() && vis[xx][yy] == false)
        {
            vis[xx][yy] = 1;
            if (arr[xx][yy] == '0')
                bfs(xx, yy, arr, vis);
        }
    }
    return;
}
vector<string> arr(101);
void solve(ll t, ll n0, ll m0)
{
    ll n, m, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    n = n0;
    m = m0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // vector<vector<bool>> vis(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.')
            {
                arr[i][j] = '0';
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '*')
            {
                //vis[i][j] = 1;
                for (int k = 0; k < 8; k++)
                {
                    ll xx = i + dx[k];
                    ll yy = j + dy[k];
                    if (xx >= 0 && yy >= 0 && xx < n && yy < m && arr[xx][yy] != '*')
                    {
                        arr[xx][yy]++;
                    }
                }
            }
        }
    }
    // c = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (arr[i][j] == '0' && vis[i][j] == false)
    //         {
    //             c++;
    //             vis[i][j] = 1;
    //             bfs(i, j, arr, vis);
    //         }
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (vis[i][j] == false)
    //         {
    //             c++;
    //         }
    //     }
    // }

    cout << "Field#" << t << "";
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }

    //cout << c;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1, n, m;
    // cin >> t;
    // for (int t0 = 1; t0 <= t; t0++)
    // {
    //     cout << "Field#" << t0 << "";
    //     solve();
    //     cout << "\n";
    // }

    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        solve(t, n, m);
        t++;
    }
    return 0;
}