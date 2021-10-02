
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define vii vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
void dfs1(int u, int p, vector<vll> &egg, vll &lev, ll &a1)
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
        dfs1(v, u, egg, lev, a1);
    }
}
void solve()
{
    ll a, b, n, q, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n;
    m = n - 1;
    vector<vll> egg(n + 1), eggR(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        egg[a].push_back(b);
        egg[b].push_back(a);
        // eggR[b].push_back(a);
    }
    vll vis(n + 1, 0), lev(n + 1, -1);
    a = 1;
    dfs1(1, 0, egg, lev, a);
    for (int i = 0; i <= n; i++)
        lev[i] = -1;
    b = a;
    dfs1(a, 0, egg, lev, b);

    cout << a << " " << b;

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