
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
void dfs(vector<vll> &egg, ll u, vll &vis)
{
    vis[u] = 1;
    for (auto xx : egg[u])
    {
        if (vis[xx] == 0)
            dfs(egg, xx, vis);
    }
}
ll getAns(vector<vll> &egg)
{
    ll n = egg.size();
    vll vis(n, 0);
    dfs(egg, 0, vis);
    for (int i = 0; i < n; i++)
        if (vis[i] == 0)
            return i;
    return -1;
}

void solve()
{
    ll a, b, n, q, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> m;
    vector<vll> egg(n), eggR(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        egg[a].push_back(b);
        eggR[b].push_back(a);
    }
    x = getAns(egg);
    if (x != -1)
    {
        cout << "NO\n";
        cout << 1 << " " << x + 1;
        return;
    }
    x = getAns(eggR);
    if (x != -1)
    {
        cout << "NO\n";
        cout << x + 1 << " " << 1;
        return;
    }
    cout << "YES\n";

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
        //cout << "\n";
    }
    return 0;
}