#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
    ll,
    null_type,
    less_equal<ll>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
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
    cin >> n >> k;
    vector<ll> arr(n), dd;
    vll vis(n, 0);
    vll ggg(k, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ggg[i % k]++;
    }
    dd = arr;
    ll ans = 0;
    while (1)
    {
        // ll flag = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     if (i % 2 == 0)
        //     {
        //         dd[i] = arr[i] & arr[(i - k + n) % n];
        //     }
        //     else
        //     {
        //         arr[i] = dd[i] & dd[(i - k + n) % n];
        //     }
        //     if (arr[i] != dd[i])
        //         flag++;
        // }
        // if (flag == 0)
        //     break;
        // ans++;
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

//ab kahi nahi bhejna