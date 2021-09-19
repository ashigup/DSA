#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
#define mpq priority_queue<ll, vector<ll>, greater<ll>>
// #define infile cin
// #define outfile cout

void solve()
{
    ll x, n, d, a, b, y, k, c = mod, m1, m2, rr, cc;
    c = 0;
    string s1;
    cin >> d >> n >> k;
    vector<vll> arr(n, vector<ll>(3));
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        arr[i][0] = b;
        arr[i][1] = c;
        arr[i][2] = a;
    }
    sort(arr.rbegin(), arr.rend());
    multiset<pll> inRace;
    multiset<pll, greater<pll>> not_used;
    multiset<pll> currentWindow;
    for (int i = 0; i < n; i++)
    {
        while (inRace.size() && inRace.begin()->first < arr[i][0])
        {
            ll e = inRace.begin()->first;
            ll h = inRace.begin()->second;
            inRace.erase(inRace.begin());
            if (not_used.count({h, e}) == 0) //present in currentWindow
            {
                currentWindow.erase(currentWindow.find({h, e}));
                sum -= h;
            }
            else
                not_used.erase({h, e});
        }
        sum += arr[i][2];
        currentWindow.insert({arr[i][2], arr[i][1]});
        inRace.insert({arr[i][1], arr[i][2]}); //e,h
        while (not_used.size() && currentWindow.size() <= k)
        {
            ll h = not_used.begin()->first;
            ll e = not_used.begin()->second;
            not_used.erase(not_used.begin());
            sum += h;
            currentWindow.insert({h, e});
        }
        while (currentWindow.size() > k)
        {
            ll h = currentWindow.begin()->first;
            ll e = currentWindow.begin()->second;
            currentWindow.erase(currentWindow.begin());
            sum -= h;
            not_used.insert({h, e});
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}
int main()
{

    ll t = 1, n, m, a, b;
    string s1;
    cin >> t;
    for (int t0 = 1; t0 <= t; t0++)
    {
        cout << "Case #" << t0 << ": ";
        solve();
    }
    return 0;
}
