
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
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr[i] = {a, i};
    }
    sort(arr.rbegin(), arr.rend());

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}