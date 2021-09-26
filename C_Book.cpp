
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
const ll INF = 1e18;
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

bool comp1(vector<ll> a1, vector<ll> a2)
{
    if (a1[1] == a2[1])
        return a1[0] <= a2[0];
    return a1[1] <= a2[1];
}

void solve()
{
    ll a, b, n, q, m, p, x, s, z, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n;
    ll ans = 0;
    vector<set<ll>> egg(n), saves(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> a;
            a--;
            egg[i].insert(a);
            saves[a].insert(i);
        }
        //sort(egg[i].begin(), egg[i].end());
    }
    vll vis(n, 0);
    m = n;

    while (m > 0)
    {

        ans++;
        ll change = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                if (egg[i].size() == 0)
                {
                    //vis[i] = 1;
                    //m--;
                    for (ll xx : saves[i])
                    {
                        egg[xx].erase(i);
                    }
                    change++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                if (egg[i].size() == 0)
                {
                    vis[i] = 1;
                    m--;
                    change++;
                }
            }
        }

        if (change == 0)
        {
            cout << -1;
            return;
        }
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