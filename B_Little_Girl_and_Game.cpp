
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
ll modpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans % mod;
}
int dfs(vector<vector<ll>> &egg, vector<ll> &vis, ll u, vector<ll> &path)
{
    vis[u] = 1;
    path.push_back(u);
    if (path.size() == vis.size() - 1)
    {
        return 1;
    }
    for (auto v : egg[u])
    {
        if (vis[v] == 0)
        {
            if (dfs(egg, vis, v, path) == 1)
                return 1;
        }
    }
    vis[u] = 0;
    path.pop_back();
    return 0;
}
int parent(int u, vector<ll> &par)
{
    if (par[u] == u)
        return u;
    par[u] = parent(par[u], par);
    return par[u];
}
void union1(int u, int v, vector<ll> &par)
{
    int x = parent(u, par);
    int y = parent(v, par);
    if (x != y)
        par[x] = y;
    return;
}
bool comp1(vector<ll> a1, vector<ll> a2)
{
    if (a1[1] == a2[1])
        return a1[0] <= a2[0];
    return a1[1] <= a2[1];
}
void solve()
{
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> s1;
    map<char, ll> mp;
    for (auto xx : s1)
        mp[xx]++;
    c = 0;
    while (1)
    {
        ll f = 0;
        for (char ch = 'a'; ch <= 'z'; ch++)
            f += (mp[ch] % 2);
        if (f <= 1)
        {
            break;
        }
        f = 0;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (mp[ch] > 0 && mp[ch] % 2 == 0)
            {
                mp[ch]--;
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (mp[ch] > 0)
                {
                    mp[ch]--;
                    f = 1;
                    break;
                }
            }
        }

        c++;
    }

    s2 = c % 2 == 0 ? "First" : "Second";
    cout << s2;
    return;
}
int main()
{
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}