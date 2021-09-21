
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
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> n;
    vll odd, even;
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a % 2 == 0)
            even.push_back(a);
        else
            odd.push_back(a);
    }
    if (even.size() == 0 || odd.size() == 0)
    {
        cout << -1;
        return;
    }
    for (auto xx : even)
    {
        cout << xx << " ";
    }
    for (auto xx : odd)
    {
        cout << xx << " ";
    }

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