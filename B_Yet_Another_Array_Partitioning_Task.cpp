
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
void solve()
{
    ll n, m, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    cin >> n >> m >> k;
    vll arr(n);
    vpll cpp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cpp[i] = {arr[i], i};
    }

    vll vis(n, 0);
    sort(cpp.begin(), cpp.end());
    reverse(cpp.begin(), cpp.end());
    ll sum = 0;
    for (int i = 0; i < m * k; i++)
    {
        vis[cpp[i].second] = 1;
        sum += cpp[i].first;
        //cout << cpp[i].second << "-";
    }
    cout << sum << "\n";
    a = 0;
    b = 0;
    for (int i = 0; i < n && b < k - 1; i++)
    {
        if (a > 0 && a % m == 0)
        {
            cout << i << " ";
            a = 0;
            b++;
        }
        if (vis[i] == 1)
            a++;
    }

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