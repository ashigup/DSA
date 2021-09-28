
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
// get topological Sort /topoSort
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
// Print Strongly connected components
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
    cin >> n >> m;
    vector<vll> egg(n), eggR(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        egg[a].push_back(b);
        eggR[b].push_back(a); //transpose of matrix
    }
    stack<ll> st;
    vector<ll> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(egg, i, vis, st);
        }
    }
    vll compp(n, -1);
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    ll label = 0;
    while (!st.empty())
    {
        ll u = st.top();
        st.pop();
        if (vis[u] == 0)
        {
            label++;
            dfsStrong(eggR, u, vis, compp, label);
        }
    }
    cout << label << "\n";
    for (int i = 0; i < n; i++)
        cout << compp[i] << " ";
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