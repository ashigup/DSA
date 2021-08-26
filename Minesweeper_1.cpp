
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
void solve()
{
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '.')
            {
                arr[i][j] = '0';
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '*')
            {
                vis[i][j] = 1;
                for (int k = 0; k < 8; k++)
                {
                    ll xx = i + dx[k];
                    ll yy = j + dy[k];
                    if (xx >= 0 && yy >= 0 && xx < n && yy < n && arr[xx][yy] != '*')
                    {
                        arr[xx][yy]++;
                    }
                }
            }
        }
    }
    c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '0' && vis[i][j] == false)
            {
                c++;
                vis[i][j] = 1;
                bfs(i, j, arr, vis);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == false)
            {
                c++;
            }
        }
    }

    // cout << "\n";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << "\n";
    // }

    cout << c;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    for (int t0 = 1; t0 <= t; t0++)
    {
        cout << "Case #" << t0 << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}