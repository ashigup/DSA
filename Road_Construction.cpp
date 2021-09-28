
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
void union1(ll a, ll b, vll &par, vll &counts)
{
    ll x = parent1(a, par);
    ll y = parent1(b, par);
    if (x == y)
        return;
    par[y] = par[x];
    counts[x] += counts[y];
}
void solve()
{
    ll a, b, n, q, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> m;
    // vector<vll> edges(m, vll(3));
    ll numComp = n, sizComp = 1;
    vll par(n), counts(n, 1);
    for (int i = 0; i < n; i++)
        par[i] = i;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        x = parent1(a, par);
        y = parent1(b, par);
        if (x == y)
        {
        }
        else
        {
            union1(x, y, par, counts);
            sizComp = max(sizComp, counts[parent1(x, par)]);
            numComp--;
        }
        cout << numComp << " " << sizComp << "\n";
    }
    // cout << ans;
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