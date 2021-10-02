
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
void dfs(vector<vll> &egg, ll u, vll &vis, vector<int> &st)
{
    vis[u] = 1;
    st.push_back(u);
    int flag = 1;
    for (auto xx : egg[u])
    {
        if (vis[xx] == 0)
        {
            flag = 0;
            dfs(egg, xx, vis, st);
        }
    }
    if (flag == 1)
        st.push_back(u);
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
        // eggR[b].push_back(a);
    }
    vll vis(n, 0);

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