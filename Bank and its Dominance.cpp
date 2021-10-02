
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>

void solve()
{
    ll a, b, n, q, m, p, x, s, y, k, c = mod, m1, m2, rr, cc;
    string s1, s2;
    cin >> s1;
    vll arr;
    c = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == '0')
            c++;
        else
        {
            if (c > 0)
                arr.push_back(c);
            c = 0;
        }
    }
    if (c > 0)
    {
        arr.push_back(c);
    }
    if (arr.size() == 0)
    {
        cout << 'B';
        return;
    }

    sort(arr.rbegin(), arr.rend());
    if (arr.size() == 1)
    {
        if (arr[0] % 2 == 1)
            cout << 'A';
        else
            cout << 'B';
        return;
    }
    else if (arr.size() > 1)
    {
        if (arr[0] == arr[1])
            cout << 'B';
        else if (arr[0] % 2 == 1)
            cout << 'A';
        else
            cout << 'B';
        return;
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
        // cout << "\n";
    }
    return 0;
}