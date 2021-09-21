
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
    string s1;
    cin >> n;
    vll arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<ll> dp(n, 0);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = arr[i];
        if (arr[i] > arr[i - 1])
        {
            dp[i]--;
        }
    }
    c = 1;
    for (int i = 0; i < n; i++)
    {
        c *= dp[i];
    }
    cout << c;
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