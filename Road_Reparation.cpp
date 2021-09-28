
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
ll parent1(ll a, vll &par)
{
    if (par[a] == a)
        return a;
    return par[a] = parent1(par[a], par);
}
void union1(ll a, ll b, vll &par)
{
    ll x = parent1(a, par);
    ll y = parent1(b, par);
    if (x == y)
        return;
    par[x] = par[y];
}
void solve()
{
    ll a, b, n, q, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> m;
    vector<vll> edges(m, vll(3));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][1], edges[i][1]--;
        cin >> edges[i][2], edges[i][2]--;
        cin >> edges[i][0];
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    vll par(n);
    for (int i = 0; i < n; i++)
        par[i] = i;
    for (int i = 0; i < m; i++)
    {
        x = parent1(edges[i][1], par);
        y = parent1(edges[i][2], par);
        if (x == y)
            continue;
        union1(x, y, par);
        ans += edges[i][0];
    }
    for (int i = 1; i < n; i++)
    {
        if (parent1(i, par) != parent1(0, par))
        {
            cout << "IMPOSSIBLE";
            return;
        }
    }
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