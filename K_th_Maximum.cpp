
#define ll long long int
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define pbds tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
// using namespace __gnu_pbds;
#define mod 1000000007
using namespace std;
#define vll vector<ll>
vector<ll> nextGreater(vector<ll> &arr)
{
    vll dp(arr.size());
    ll n = arr.size();
    stack<pair<ll, ll>> s;
    s.push({arr[0], 0});
    for (int i = 1; i < n; i++)
    {
        if (s.empty())
        {
            s.push({arr[i], i});
            continue;
        }
        while (s.empty() == false && s.top().first < arr[i])
        {
            dp[s.top().second] = (i - s.top().second - 1);
            //cout << s.top().first                 << " --> " << i - s.top().second - 1 << endl;
            s.pop();
        }
        s.push({arr[i], i});
    }
    while (s.empty() == false)
    {
        dp[s.top().second] = (n - s.top().second - 1);
        //cout << s.top().first << " --> " << (n - s.top().second - 1) << endl;
        s.pop();
    }
    return dp;
}
void solve()
{
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    c = 0;
    a = arr[0];
    for (int i = 0; i < n; i++)
    {
        a = max(a, arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
        {
            if (i >= k - 1)
                c += (n - i);
        }
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