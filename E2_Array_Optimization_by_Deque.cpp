
#define ll long long int
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
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
    cin >> n;
    vll arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    deque<ll> qq;
    ordered_set st;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += min(st.order_of_key(arr[i]), st.size() - st.order_of_key(arr[i] + 1));
        st.insert(arr[i]);
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