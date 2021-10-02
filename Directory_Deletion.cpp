
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define vii vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
//farthest Node in a Tree from u is a1
void farthestNode(int u, int p, vector<vll> &egg, vll &lev, ll &a1)
{
    lev[u] = lev[p] + 1;
    if (lev[a1] <= lev[u])
    {
        a1 = u;
    }
    for (auto v : egg[u])
    {
        if (v == p)
            continue;
        farthestNode(v, u, egg, lev, a1);
    }
}
int dfs(int u, int p, vector<vll> &egg, vll &del)
{
    if (del[u] == 1)
        return 1;
    int ans = 0;
    for (auto v : egg[u])
    {
        if (v == p)
            continue;
        ans += dfs(v, u, egg, del);
    }
    return ans;
}
void solve()
{
    ll a, b, n, q, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n;
    m = n - 1;
    vector<vll> egg(n + 1), eggR(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (i == 0)
            continue;
        egg[i + 1].push_back(a);
        egg[a].push_back(i + 1);
        // eggR[b].push_back(a);
    }
    cin >> m;
    vll del(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        del[a] = 1;
    }
    int ans = 0;
    ans = dfs(1, 0, egg, del);
    // for (auto v : egg[1])
    // {
    //     ans += dfs(v, 1, egg, del);
    // }

    cout << ans;

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}