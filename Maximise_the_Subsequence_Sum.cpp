
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
    cin >> n >> k;
    vll arr;
    c = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a <= 0)
            arr.push_back(a);
        else
            c += a;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < min((ll)arr.size(), k); i++)
    {
        c -= arr[i];
    }
    cout << c;
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