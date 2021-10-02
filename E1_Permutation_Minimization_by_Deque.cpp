
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
    vll arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    deque<ll> qq;
    for (ll i = 0; i < n; i++)
    {
        if (qq.empty())
        {
            qq.push_front(arr[i]);
            continue;
        }
        if (qq.front() > arr[i])
        {
            qq.push_front(arr[i]);
        }
        else
        {
            qq.push_back(arr[i]);
        }
    }
    for (auto xx : qq)
    {
        cout << xx << " ";
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
        cout << "\n";
    }
    return 0;
}