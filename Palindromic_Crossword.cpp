
#include <bits/stdc++.h>
#define ll int
#define pll pair<ll, ll>
using namespace std;
#define mod 1000000007
#define vll vector<ll>
ll dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
ll dy[] = {-1, 0, 1, -1, 0, 1, 1, -1};

map<vector<ll>, bool> ccc;
vector<ll> tmm(4);
void getVer(vector<string> &arr, int n, int m)
{
    int ii, jj;
    for (int i = 0; i < m; i++)
    {
        ii = jj = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] != '#')
            {
                jj++;
            }
            else
            {
                if (jj - ii > 1)
                {
                    jj--;
                    while (ii < jj)
                    {
                        tmm = {ii, i, jj, i};
                        ccc[tmm] = 1;
                        ii++;
                        jj--;
                    }
                }
                ii = jj = j + 1;
            }
        }
        if (jj - ii > 1)
        {
            jj--;
            while (ii < jj)
            {
                tmm = {ii, i, jj, i};
                ccc[tmm] = 1;
                ii++;
                jj--;
            }
        }
    }
    //cout << ans.size() << "---\n";
    return;
}
void getHori(vector<string> &arr, int n, int m)
{
    int ii, jj;
    for (int i = 0; i < n; i++)
    {
        ii = jj = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != '#')
            {
                jj++;
            }
            else
            {
                if (jj - ii > 1)
                {
                    jj--;
                    while (ii < jj)
                    {
                        tmm = {ii, i, jj, i};
                        ccc[tmm] = 1;
                        ii++;
                        jj--;
                    }
                }
                ii = jj = j + 1;
            }
        }

        if (jj - ii > 1)
        {
            jj--;
            while (ii < jj)
            {
                tmm = {ii, i, jj, i};
                ccc[tmm] = 1;
                ii++;
                jj--;
            }
        }
    }
    //cout << ans.size() << "---\n";
    return;
}
void solve()
{
    ll n, m, a, b, x, y, k, c, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> m;
    c = 0;
    ccc.clear();
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<pair<ll, ll>>> ss;
    getVer(arr, n, m);
    getHori(arr, n, m);

    // for (auto row : ver)
    // {
    //     for (auto pt : row)
    //     {
    //         cout << arr[pt.first][pt.second];
    //     }
    //     ss.push_back(row);
    //     cout << "\n";
    // }
    // for (auto row : hori)
    // {
    //     for (auto pt : row)
    //     {
    //         cout << arr[pt.first][pt.second];
    //     }
    //     ss.push_back(row);
    //     cout << "\n";
    // }
    // cout << ss.size() << "----\n";
    // sort(ss.begin(), ss.end(), comp);
    // c = 0;
    // for (int seq = 0; seq < ss.size(); seq++)
    // {
    //     vector<pair<ll, ll>> xx = ss[seq];
    //     int i = 0;
    //     int j = xx.size() - 1;
    //     while (i < j)
    //     {
    //         pair<ll, ll> p1 = xx[i];
    //         pair<ll, ll> p2 = xx[j];
    //         int x1 = p1.first;
    //         int x2 = p2.first;
    //         int y1 = p1.second;
    //         int y2 = p2.second;
    //         if (arr[x1][y1] == arr[x2][y2] && arr[x1][y1] != '.')
    //         {
    //             i++;
    //             j--;
    //             continue;
    //         }
    //         else if (arr[x1][y1] != '.')
    //         {
    //             arr[x2][y2] = arr[x1][y1];
    //             c++;
    //         }
    //         else if (arr[x2][y2] != '.')
    //         {
    //             arr[x1][y1] = arr[x2][y2];
    //             c++;
    //         }
    //     }
    // }
    queue<vector<ll>> qq;
    for (auto par : ccc)
    {
        qq.push(par.first);
    }
    while (!qq.empty())
    {
        ll siz = qq.size();
        for (int i = 0; i < siz; i++)
        {
            auto pp = qq.front();
            qq.pop();
            int x1 = pp[0];
            int y1 = pp[1];
            int x2 = pp[2];
            int y2 = pp[3];
            return;
            if (arr[x1][y1] == arr[x2][y2])
            {
                if (arr[x1][y1] == '.')
                    qq.push({x1, y1, x2, y2});
                continue;
            }
            else if (arr[x1][y1] != '.')
            {
                arr[x2][y2] = arr[x1][y1];
                c++;
            }
            else if (arr[x2][y2] != '.')
            {
                arr[x1][y1] = arr[x2][y2];
                c++;
            }
        }
        if (qq.size() == siz)
            break;
    }

    cout << c << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1, n, m;
    cin >> t;
    for (int t0 = 1; t0 <= t; t0++)
    {
        cout << "Case #" << t0 << ": ";
        solve();
        //cout << "\n";
    }

    return 0;
}