
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>

ll arr[100005], bbb[100005];
void solve()
{
    ll n, m, a, l, r, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    cin >> n;
    c = a = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        a -= arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> bbb[i];
        a += bbb[i];
    }
    c = 1e15;
    for (int i = 0; i < n; i++)
    {
        x = a + arr[i];
        if (x > 0)
        {
            if ((x % (n - 1)) == 0 && (x / (n - 1)) > 0)
            {
                c = min(c, x / (n - 1));
            }
        }
    }

    cout << c;
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