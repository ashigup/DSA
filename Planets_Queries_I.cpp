
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

bool comp1(vector<ll> a1, vector<ll> a2)
{
    if (a1[1] == a2[1])
        return a1[0] <= a2[0];
    return a1[1] <= a2[1];
}
ll parent[200005][31];
void solve()
{
    ll a, b, n, q, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> q;
    //Construct a parent matrix (where parent[i][d]  is the 2^0=1st parent of i )
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        a--;
        parent[i][0] = a;
    }

    //Construct a parent matrix (where parent[i][d]  is the 2^d th parent of i )
    for (int i = 1; i < 30 + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
    while (q--)
    {
        cin >> x >> k;
        x--;
        // cout << x << "\n";
        // continue;
        for (int i = 0; i < 30 + 1; i++)
        {
            if (k & (1 << i))
            {
                x = parent[x][i];
            }
        }
        cout << x + 1 << "\n";
    }
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
        //cout << "\n";
    }
    return 0;
}