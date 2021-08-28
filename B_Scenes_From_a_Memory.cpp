
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
void solve()
{
    ll n, m, a, l, r, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    cin >> n >> s1;
    map<ll, ll> mp;
    vll arr = {1, 4, 6, 8, 9};
    for (auto xx : s1)
    {
        mp[xx - '0']++;
    }
    for (auto xx : arr)
    {
        if (mp[xx] > 0)
        {
            cout << "1\n"
                 << xx;
            return;
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        if (mp[i] > 1)
        {
            cout << "2\n"
                 << i << i;
            return;
        }
    }

    if ((mp[2] == 1 && s1[0] != '2'))
    {
        cout << "2\n"
             << s1[0] << "2";
        return;
    }
    if ((mp[5] == 1 && s1[0] != '5'))
    {
        cout << "2\n"
             << s1[0] << "5";
        return;
    }
    if (mp[7] == 1 && (mp[2] > 0 || mp[5] > 0))
    {
        cout << "2\n"
             << (mp[2] > 0 ? 2 : 5) << "7";
        return;
    }
    cout << "2\n"
         << "57";
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