

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
    priority_queue<pair<ll, ll>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr[i] = {a, i + 1};
        if (a > 0)
            pq.push({a, i + 1});
    }
    vector<vll> ans;
    while (pq.size() > 1)
    {
        auto aa = pq.top();
        pq.pop();
        auto bb = pq.top();
        pq.pop();
        ans.push_back({aa.second, bb.second});
        aa.first--;
        bb.first--;
        if (aa.first > 0)
            pq.push(aa);
        if (bb.first > 0)
            pq.push(bb);
    }
    cout << ans.size() << "\n";
    for (auto &v : ans)
    {
        cout << v[0] << " " << v[1] << "\n";
    }

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
        // cout << "\n";
    }
    return 0;
}