
#define ll long long int
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define pbds tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
// using namespace __gnu_pbds;
#define mod 1000000007
using namespace std;
#define vll vector<ll>
vector<ll> xors(300005, 0);

ll dp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0};
ll fun(ll i, vector<ll> &num)
{
    if (i == num.size())
        return 1;
    if (num[i] == 0)
        return fun(i + 1, num);
    else if (num[i] > 19)
        return 0;
    ll ans = dp[num[i]] * fun(i + 1, num);

    if (i + 2 < num.size())
    {
        ll tmp = num[i + 2] + 10;
        ll cx = num[i + 2];
        num[i + 2] = tmp;
        ans += fun(i + 1, num) * dp[num[i] - 1];
        num[i + 2] = cx;
    }
    return ans;
}
void solve()
{
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    cin >> s1;

    vll arr;

    for (auto c : s1)
        arr.push_back(c - '0');
    c = fun(0, arr) - 2;
    cout << c;
    return;
}
int main()
{
    ll t = 1;
    cin >> t;
    for (int i = 1; i < 300005; i++)
        xors[i] = xors[i - 1] ^ i;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}