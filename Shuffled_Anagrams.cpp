
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define vll vector<ll>
ll dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
ll dy[] = {-1, 0, 1, -1, 0, 1, 1, -1};

void solve()
{
    ll n, m, a, b, x, y, k, c, m1, m2, rr, cc;
    string s1, s2;
    cin >> s1;
    s2 = s1;
    n = s1.size();
    map<int, ll> mp;
    map<int, vector<ll>> store;
    for (int i = 0; i < n; i++)
    {
        mp[s1[i] - 'a']++;
        store[s1[i] - 'a'].push_back(i);
    }
    vector<pair<ll, char>> prrs;
    for (auto xx : mp)
    {
        if (n - xx.second < xx.second)
        {
            cout << "IMPOSSIBLE";
            return;
        }
        prrs.push_back({xx.second, xx.first});
    }
    sort(prrs.rbegin(), prrs.rend());
    vll arr;
    for (auto pr : prrs)
    {
        for (auto xx : store[pr.second])
            arr.push_back(xx);
    }
    for (auto seq : arr)
    {
        int ch = s1[seq] - 'a';
        ch = (ch + 1) % 26;
        for (int m = ch; m != s1[seq] - 'a'; m = (m + 1) % 26)
        {
            if (mp[m] > 0)
            {
                mp[m]--;
                s2[seq] = 'a' + m;
                break;
            }
        }
    }
    cout << s2;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1, n, m;
    cin >> t;
    for (int t0 = 1; t0 <= t; t0++)
    {
        cout << "Case #" << t0 << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}