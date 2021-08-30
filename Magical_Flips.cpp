
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
    cin >> n;
    c = a = 0;
    vll arr(n), bbb(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> bbb[i];
    }
    vll dpa(n), dpb(n);

    dpa[0] = arr[0];
    dpb[0] = bbb[0];
    for (int i = 1; i < n; i++)
    {
        dpa[i] = max(dpa[i - 1] & arr[i], dpb[i - 1] & arr[i]);
        dpb[i] = max(dpa[i - 1] & bbb[i], dpb[i - 1] & bbb[i]);
    }
    a = max(dpa[n - 1], dpb[n - 1]);

    // dpb[0] = arr[0];
    // dpa[0] = bbb[0];
    // for (int i = 1; i < n; i++)
    // {
    //     dpa[i] = max(dpa[i - 1] & arr[i], dpa[i - 1] & bbb[i]);
    //     dpb[i] = max(dpb[i - 1] & arr[i], dpb[i - 1] & bbb[i]);
    // }
    // a = max(max(a, dpa[n - 1]), max(a, dpb[n - 1]));

    c = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & a) == a)
        {
        }
        else
            c++;
    }

    cout << a << " " << c;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}