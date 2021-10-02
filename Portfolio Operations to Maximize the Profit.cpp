
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>

void solve()
{
    ll a, b, n, q, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> m >> p;
    vll arr(n), bbb(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] += (i - 1 < 0 ? 0 : arr[i - 1]);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> bbb[i];
        bbb[i] += (i - 1 < 0 ? 0 : bbb[i - 1]);
    }
    ll ans = 0;
    ll i1 = 0, j1 = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] <= p)
            i1++;
    for (int i = i1 - 1; i >= 0; i--)
    {
        while (j1 < m && bbb[j1] + arr[i] <= p)
            j1++;
        ans = max(ans, (i + 1) + j1);
    }
    cout << ans;

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
        // cout << "\n";
    }
    return 0;
}