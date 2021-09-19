#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define mpq priority_queue<ll, vector<ll>, greater<ll>>
// #define infile cin
// #define outfile cout
const ll INF = 1e18;

bool comp(vector<ll> &a, vector<ll> &b)
{
    return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
}
int orientation(vector<ll> &p, vector<ll> &q, vector<ll> &r)
{
    int orient = (q[1] - p[1]) * (r[0] - q[0]) - (r[1] - q[1]) * (q[0] - p[0]);
    if (orient == 0)
        return 0;
    return (orient > 0 ? 1 : 2);
}
vector<vector<ll>> outerTrees(vector<vector<ll>> &trees)
{
    int n = trees.size();
    if (n <= 3)
        return trees;
    vector<vector<ll>> ans;
    sort(trees.begin(), trees.end(), comp);

    for (int i = 0; i < n; i++)
    {
        while (ans.size() > 1 && orientation(ans[ans.size() - 1 - 1], ans.back(), trees[i]) == 2)
            ans.pop_back();
        ans.push_back(trees[i]);
    }
    if (ans.size() == n)
        return ans;

    for (int i = n - 2; i >= 0; i--)
    {
        while (ans.size() > 1 && orientation(ans[ans.size() - 1 - 1], ans.back(), trees[i]) == 2)
            ans.pop_back();
        ans.push_back(trees[i]);
    }
    ans.pop_back();
    return ans;
}
ll areaT(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll are = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
    return are;
}
double distance(ll x1, ll y1, ll x2, ll y2)
{
    double dis = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.00);
    return dis;
}
bool isInside(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x, ll y)
{
    ll A = areaT(x1, y1, x2, y2, x3, y3);
    ll A1 = areaT(x, y, x2, y2, x3, y3);
    ll A2 = areaT(x1, y1, x, y, x3, y3);
    ll A3 = areaT(x1, y1, x2, y2, x, y);
    return (A == A1 + A2 + A3);
}
double perimeter(vector<vector<ll>> &ans)
{
    double perimeter = 0.0;

    // Find the distance between adjacent points
    for (int i = 0; i < ans.size() - 1; i++)
    {
        perimeter += distance(ans[i][0], ans[i][1], ans[i + 1][0], ans[i + 1][1]);
    }

    // Add the distance between first and last point
    perimeter += distance(ans[0][0], ans[0][1], ans[ans.size() - 1][0], ans[ans.size() - 1][1]);

    return perimeter;
}

void solve()
{
    ll x, n, d, a, b, y, k, c = mod, m1, m2, rr, cc;
    c = 0;
    string s1;
    cin >> n;
    set<vector<ll>> se;
    vector<vector<ll>> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        se.insert({a, b});
    }
    cin >> x >> y;
    se.insert({x, y});
    arr.insert(arr.end(), se.begin(), se.end());
    vector<vll> hull = outerTrees(arr);
    for (int i = 0; i < hull.size(); i++)
    {
        if (hull[i][0] == x && hull[i][1] == y)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    if (hull.size() <= 2)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    double ans = INF;

    ans = min(ans, perimeter(hull));
    for (int i = 0; i < hull.size(); i++)
    {
        for (int j = 0; j < hull.size(); j++)
        {
            if (i == j)
                continue;
            for (int h = 0; h < hull.size(); h++)
            {
                if (i == h || j == h)
                    continue;
                k = 0;

                vector<vector<ll>> pts;
                pts.push_back(hull[i]);
                pts.push_back(hull[j]);
                pts.push_back(hull[h]);
                pts.push_back({x, y});
                vector<vector<ll>> ptshull = outerTrees(pts);
                for (auto xx : ptshull)
                {
                    if (xx[0] == x && xx[1] == y)
                    {
                        k = 1;
                        break;
                    }
                }
                // if (ptshull.size() != 3)
                //     k = 1;
                // if (!isInside(hull[i][0], hull[i][1], hull[j][0], hull[j][1], hull[h][0], hull[h][1], x, y))
                //     k = 1;

                if (k == 0)
                {
                    ans = min(ans, perimeter(ptshull));
                }
            }
        }
    }
    if (ans == INF)
    {
        for (int i = 0; i < hull.size(); i++)
        {
            for (int j = i + 1; j < hull.size(); j++)
            {
                for (int h = j + 1; h < hull.size(); h++)
                {
                    for (int g = h + 1; g < hull.size(); g++)
                    {
                        k = 0;
                        vector<vector<ll>> pts;
                        pts.push_back(hull[i]);
                        pts.push_back(hull[j]);
                        pts.push_back(hull[h]);
                        pts.push_back(hull[g]);
                        pts.push_back({x, y});
                        vector<vector<ll>> ptshull = outerTrees(pts);
                        for (auto xx : ptshull)
                        {
                            if (xx[0] == x && xx[1] == y)
                            {
                                k = 1;
                                break;
                            }
                        }
                        if (k == 0)
                        {
                            pts.clear();
                            pts.push_back(hull[i]);
                            pts.push_back(hull[j]);
                            pts.push_back(hull[h]);
                            pts.push_back(hull[g]);
                            ans = min(ans, perimeter(ptshull));
                            ans = min(ans, perimeter(pts));
                        }
                    }
                }
            }
        }
    }
    cout
        << fixed
        << setprecision(6)
        << ans
        << "\n";
}
int main()
{

    ll t = 1, n, m, a, b;
    string s1;
    cin >> t;
    for (int t0 = 1; t0 <= t; t0++)
    {
        cout << "Case #" << t0 << ": ";
        solve();
    }
    return 0;
}
