
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
void solve()
{
    ll n, m, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2 = "YES";
    cin >> n >> m >> k;
    set<ll> verS, horiS;
    vector<pair<ll, ll>> pipl(k), piplT(k);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        verS.insert(a);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        horiS.insert(a);
    }

    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        pipl[i] = {a, b};
        piplT[i] = {b, a};
    }
    sort(pipl.begin(), pipl.end());
    sort(piplT.begin(), piplT.end());
    ll ans = 0;
    a = c = 0;
    for (set<ll>::iterator it = ++verS.begin(); it != verS.end() && a < k; it++)
    {
        set<ll>::iterator cp = it;
        cp--;
        int s = *cp;
        int e = *it;
        map<ll, ll> mp;
        for (; a < k && pipl[a].first == s; a++)
        {
        }
        for (; a < k && pipl[a].first > s && pipl[a].first < e; a++)
        {
            if (horiS.find(pipl[a].second) != horiS.end())
            {
                mp[pipl[a].second]++;
            }
        }
        x = c = 0;
        for (auto xx : mp)
        {
            c += x * xx.second;
            x += xx.second;
        }
        ans += c;
    }
    a = c = 0;
    for (set<ll>::iterator it = ++horiS.begin(); it != horiS.end() && a < k; it++)
    {
        set<ll>::iterator cp = it;
        cp--;
        int s = *cp;
        int e = *it;
        map<ll, ll> mp;
        for (; a < k && piplT[a].first == s; a++)
        {
        }
        for (; a < k && piplT[a].first > s && piplT[a].first < e; a++)
        {
            if (verS.find(piplT[a].second) != verS.end())
            {
                mp[piplT[a].second]++;
            }
        }
        x = c = 0;
        for (auto xx : mp)
        {
            c += x * xx.second;
            x += xx.second;
        }
        ans += c;
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        //cout << "\n";
    }
    return 0;
}