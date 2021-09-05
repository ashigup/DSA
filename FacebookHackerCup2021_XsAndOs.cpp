
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vch vector<char>

pair<ll, ll> solve(vector<string> arr)
{
    ll n, m, a, l, r, b, x, k, y, c, d, m1, m2, rr, cc;
    //string s1, s2;
    n = arr.size();
    vpll cols(n, {0, 0}), rows(n, {0, 0});
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 'X')
            {
                cols[j].first++;
                rows[i].first++;
            }
            else if (arr[i][j] == 'O')
            {
                cols[j].second++;
                rows[i].second++;
            }
        }
    }
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        if (cols[i].first != 0 && cols[i].second != 0)
        {
        }
        else if (cols[i].second == 0 && n - cols[i].first > 1)
        {
            mp[n - cols[i].first]++;
        }
        if (rows[i].first != 0 && rows[i].second != 0)
        {
        }
        else if (rows[i].second == 0 && n - rows[i].first > 1)
        {

            mp[n - rows[i].first]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '.')
            {
                if (cols[j].first + 1 == n)
                {
                    mp[1]++;
                }
                else if (rows[i].first + 1 == n)
                {
                    mp[1]++;
                }
            }
        }
    }
    if (mp.size() > 0)
    {
        return {mp.begin()->first, mp.begin()->second};
    }
    return {-1, -1};
}
int main()
{
    // ifstream cin("xs_and_os_input.txt");
    // ofstream cout("xs_and_os_output.txt");
    ll t = 1, n;
    cin >> t;
    string s1, s2;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<string> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "Case #" << i + 1 << ": ";
        pair<ll, ll> ccc = solve(arr);

        if (ccc.first == -1)
        {
            cout << "Impossible";
        }
        else
            cout << ccc.first << " " << ccc.second;
        cout << "\n";
    }
    // while (t--)
    // {
    //     solve();
    //     cout << "\n";
    // }
    return 0;
}