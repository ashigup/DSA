
#define ll long long int
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define pbds tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
// using namespace __gnu_pbds;
#define mod 1000000007
using namespace std;
#define vll vector<ll>

void solve()
{
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    map<ll, vector<ll>> req;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr[i] = {a, i};
        req[i - a].push_back(i);
    }
    if (req.size() == 1)
        c = req.begin()->second.size();
    else
        c = 1;
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