
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

void solve()
{
    ll a, b, n, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n >> p;
    vector<vector<ll>> data(n, vector<ll>(2, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> data[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> data[i][1];
    }
    for (int i = 0; i < n; i++)
    {
        data[i][0] = pow(data[i][0], 2) + pow(data[i][1], 2);
        cin >> data[i][1];
    }
    sort(data.begin(), data.end());
    for (int i = 1; i < n; i++)
    {
        data[i][1] += data[i - 1][1];
    }
    ll ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (data[i][1] >= p)
        {
            if (ans == -1)
                ans = data[i][0];
            break;
        }
    }
    if (ans != -1)
        ans = ceil(sqrt(ans));
    cout << ans;
    return;
}
int main()
{
    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}