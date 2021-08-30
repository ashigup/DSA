
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
    vector<ll> arr(n);
    c = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vll pk;
    if (arr[0] >= arr[1])
    {
        pk.push_back(0);
    }
    else
    {
        cout << -1;
        return;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
        {
            if (arr[i] <= arr[pk.back()])
            {
                pk.push_back(i);
            }
            else
            {
                cout << -1;
                return;
            }
        }
    }
    a = 0;
    reverse(arr.begin(), arr.end());
    c = 0;
    for (int i = 0; i < n;)
    {

        ll flag = 0;
        while (i + 1 < n && arr[i + 1] <= arr[a])
        {
            flag++;
            i++;
        }
        i++;
        if (flag != 0)
        {
            c++;
            a = i;
        }
    }
    if (a < n - 1)
    {
        cout << -1;
        return;
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