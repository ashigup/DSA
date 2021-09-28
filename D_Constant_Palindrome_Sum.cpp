
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
void dfs(vector<vll> &egg, ll u, vll &vis, stack<ll> &st)
{
    vis[u] = 1;
    for (auto xx : egg[u])
    {
        if (vis[xx] == 0)
            dfs(egg, xx, vis, st);
    }
    st.push(u);
}
void dfsStrong(vector<vll> &egg, ll u, vll &vis, vll &comp, ll label)
{
    vis[u] = 1;
    comp[u] = label;
    for (auto xx : egg[u])
    {
        if (vis[xx] == 0)
            dfsStrong(egg, xx, vis, comp, label);
    }
}

void solve()
{
    ll a, b, n, q, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> k;
    vll arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<ll, ll> mp;
    for (int i = 1; 2 * i <= n; i++)
    {
        mp[arr[i - 1] + arr[n - (i - 1) - 1]]++;
    }
    x = k;
    ll ans = n;
    vll psum(2 * k + 2, 0);
    for (int i = 1; i * 2 <= n; i++)
    {
        a = min(arr[i - 1], arr[n - 1 - (i - 1)]) + 1;
        b = max(arr[i - 1], arr[n - 1 - (i - 1)]) + k;
        psum[a]++;
        psum[b + 1]--;
    }
    for (int i = 1; i < 2 * k + 1; i++)
    {
        psum[i] += psum[i - 1];
    }
    for (int i = 2; i <= 2 * k; i++) // for sum x=i;
    {
        //zero replacements
        ll c0 = mp[i];
        // at most 1 replacements
        ll c1 = psum[i];
        //both replacemetns
        ll c2 = (n / 2 - psum[i]) * 2;
        ans = min(ans, c1 - c0 + c2);
    }
    cout << ans;

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