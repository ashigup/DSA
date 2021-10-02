
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
    ll n, a, zz, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    cin >> zz;
    cin.ignore();
    getline(cin, s1);
    stringstream ss(s1);
    vector<pair<ll, ll>> arr;
    while (ss >> a)
    {
        arr.push_back({a, arr.size() + 1});
    }
    n = arr.size();
    sort(arr.begin(), arr.end());
    c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].first > zz)
            break;
        a = min(zz / arr[i].first, arr[i].second);
        c += a;
        zz -= a * arr[i].first;
    }
    cout << c;
    return;
}
int main()
{
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        // cout << "\n";
    }
    return 0;
}